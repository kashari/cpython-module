FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    git \
    build-essential python3-dev \
    libssl-dev libncurses5-dev libsqlite3-dev libreadline-dev libtk8.6 libgdm-dev libdb4o-cil-dev libpcap-dev

RUN git clone https://github.com/python/cpython.git /cpython

WORKDIR /cpython

RUN ./configure && make && make install

WORKDIR /app

COPY . .

RUN python3 -m pip install setuptools && python3 ./setup.py build_ext --inplace

CMD [ "/bin/bash" ]
