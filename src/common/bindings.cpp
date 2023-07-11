#include <pybind11/pybind11.h>
#include "osMethods.h"
namespace py = pybind11;

PYBIND11_MODULE(mcmod, m) {
    m.doc() = "pybind11 example";

    m.def("defPathFound", &defPathFound, "Searches for default mc installation");
}