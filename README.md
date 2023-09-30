## 3D Curves Hierarchy Project
### author Andrey Misyurov
#### Test task on C++ Junior position.

This project is a C++ implementation of a 3D curves hierarchy supporting circles, ellipses, and 3D helixes.

Remark: During the development, I noticed that a circle is a special case of an ellipse. To avoid duplicating code, I derived the Circle class from the Ellipse class.
Getting Started.

    Prerequisites:
        Libraries: gtest and gtest_main for testing.
        Optional: Docker for containerization.

    make - compile, buld libCurve, testing leaks (valgrind) and unit testing, and start main program
    make docker_build - build conteiner from Dockerfile
    make docker_run - run app into container
    make leaks - testing with valgrind
    make clean - just cleaning up
    
Note: When running the application or tests, the shared library's path is temporarily set via the LD_LIBRARY_PATH environment variable to ensure correct linkage.

Curve Definitions:

    All curves are parametric.
    Circle: Planar in XoY plane, defined by its radius.
    Ellipse: Planar in XoY plane, defined by two radii along X and Y.
    Helix: Spatial, defined by radius and step. Takes 2 * PI in parametric space for a round.
