/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include <cassert>
#include "Filter.h"
using namespace std;

Filter::Filter(const std::bitset<8> & vertices, const std::bitset<8> & nvertices) : Cube(vertices), _nvertices(nvertices) {
    assert((_vertices & _nvertices) == 0);
}

Filter::Filter(const Cube & vertices, const Cube & nvertices) : Cube(vertices), _nvertices(nvertices._vertices) {
    assert((_vertices & _nvertices) == 0);
}

bool Filter::equal(const Filter & filter) const {
    return (_vertices == filter._vertices) && (_nvertices == filter._nvertices);
}

bool Filter::place(const Cube & cube, Rotation & rotation) const {
    //for (int f = SIDES
    return (cube._vertices & _vertices) == _vertices && (cube._vertices & _nvertices) == 0;
}

void Filter::rotateX() {
    bitset<8> tmp = _vertices;
    _vertices[0] = tmp[3];
    _vertices[1] = tmp[2];
    _vertices[2] = tmp[6];
    _vertices[3] = tmp[7];
    _vertices[4] = tmp[0];
    _vertices[5] = tmp[1];
    _vertices[6] = tmp[5];
    _vertices[7] = tmp[4];
    bitset<8> ntmp = _nvertices;
    _nvertices[0] = ntmp[3];
    _nvertices[1] = ntmp[2];
    _nvertices[2] = ntmp[6];
    _nvertices[3] = ntmp[7];
    _nvertices[4] = ntmp[0];
    _nvertices[5] = ntmp[1];
    _nvertices[6] = ntmp[5];
    _nvertices[7] = ntmp[4];
    _r.rotateX();
}

void Filter::rotateY() {
    bitset<8> tmp = _vertices;
    _vertices[0] = tmp[4];
    _vertices[1] = tmp[0];
    _vertices[2] = tmp[3];
    _vertices[3] = tmp[7];
    _vertices[4] = tmp[5];
    _vertices[5] = tmp[1];
    _vertices[6] = tmp[2];
    _vertices[7] = tmp[6];
    bitset<8> ntmp = _nvertices;
    _nvertices[0] = ntmp[4];
    _nvertices[1] = ntmp[0];
    _nvertices[2] = ntmp[3];
    _nvertices[3] = ntmp[7];
    _nvertices[4] = ntmp[5];
    _nvertices[5] = ntmp[1];
    _nvertices[6] = ntmp[2];
    _nvertices[7] = ntmp[6];
    _r.rotateY();
}

void Filter::rotateZ() {
    bitset<8> tmp = _vertices;
    _vertices[0] = tmp[3];
    _vertices[1] = tmp[0];
    _vertices[2] = tmp[1];
    _vertices[3] = tmp[2];
    _vertices[4] = tmp[7];
    _vertices[5] = tmp[4];
    _vertices[6] = tmp[5];
    _vertices[7] = tmp[6];
    bitset<8> ntmp = _nvertices;
    _nvertices[0] = ntmp[3];
    _nvertices[1] = ntmp[0];
    _nvertices[2] = ntmp[1];
    _nvertices[3] = ntmp[2];
    _nvertices[4] = ntmp[7];
    _nvertices[5] = ntmp[4];
    _nvertices[6] = ntmp[5];
    _nvertices[7] = ntmp[6];
    _r.rotateZ();
}