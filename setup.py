from setuptools import setup, Extension

module = Extension("stringutil", sources=["stringutilmodule.c"])

setup(
    name="stringutil",
    version="1.0",
    ext_modules=[module],
)
