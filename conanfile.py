from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps

class FlightwaveAppConan(ConanFile):
    name = "flightwave.app"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    requires = "flightwave/3.0.0"
    generators = "CMakeDeps", "CMakeToolchain"