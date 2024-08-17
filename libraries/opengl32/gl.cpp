#include "gl.h"

void WINAPI WGOL_GL::glAccum(GLenum op, GLfloat value) {
  ::glAccum(op, value);
}

void WINAPI WGOL_GL::glAlphaFunc(GLenum func, GLclampf ref) {
  ::glAlphaFunc(func, ref);
}

GLboolean WINAPI WGOL_GL::glAreTexturesResident(GLsizei n, const GLuint* textures, GLboolean* residences) {
  return ::glAreTexturesResident(n, textures, residences);
}

void WINAPI WGOL_GL::glArrayElement(GLint index) {
  ::glArrayElement(index);
}

void WINAPI WGOL_GL::glBegin(GLenum mode) {
  ::glBegin(mode);
}

void WINAPI WGOL_GL::glEnd() {
  ::glEnd();
}

void WINAPI WGOL_GL::glBindTexture(GLenum target, GLuint texture) {
  ::glBindTexture(target, texture);
}

void WINAPI WGOL_GL::glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte* bitmap) {
  ::glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
}

void WINAPI WGOL_GL::glBlendFunc(GLenum sfactor, GLenum dfactor) {
  ::glBlendFunc(sfactor, dfactor);
}

void WINAPI WGOL_GL::glCallList(GLuint list) {
  ::glCallList(list);
}

void WINAPI WGOL_GL::glCallLists(GLsizei n, GLenum type, const GLvoid* lists) {
  ::glCallLists(n, type, lists);
}

void WINAPI WGOL_GL::glClear(GLbitfield mask) {
  ::glClear(mask);
}

void WINAPI WGOL_GL::glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
  ::glClearAccum(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
  ::glClearColor(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glClearDepth(GLclampd depth) {
  ::glClearDepth(depth);
}

void WINAPI WGOL_GL::glClearIndex(GLfloat c) {
  ::glClearIndex(c);
}

void WINAPI WGOL_GL::glClearStencil(GLint s) {
  ::glClearStencil(s);
}

void WINAPI WGOL_GL::glClipPlane(GLenum plane, const GLdouble* equation) {
  ::glClipPlane(plane, equation);
}

void WINAPI WGOL_GL::glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
  ::glColor3b(red, green, blue);
}

void WINAPI WGOL_GL::glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
  ::glColor3d(red, green, blue);
}

void WINAPI WGOL_GL::glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
  ::glColor3f(red, green, blue);
}

void WINAPI WGOL_GL::glColor3i(GLint red, GLint green, GLint blue) {
  ::glColor3i(red, green, blue);
}

void WINAPI WGOL_GL::glColor3s(GLshort red, GLshort green, GLshort blue) {
  ::glColor3s(red, green, blue);
}

void WINAPI WGOL_GL::glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
  ::glColor3ub(red, green, blue);
}

void WINAPI WGOL_GL::glColor3ui(GLuint red, GLuint green, GLuint blue) {
  ::glColor3ui(red, green, blue);
}

void WINAPI WGOL_GL::glColor3us(GLushort red, GLushort green, GLushort blue) {
  ::glColor3us(red, green, blue);
}

void WINAPI WGOL_GL::glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
  ::glColor4b(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
  ::glColor4d(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
  ::glColor4f(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
  ::glColor4i(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
  ::glColor4s(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
  ::glColor4ub(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
  ::glColor4ui(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
  ::glColor4us(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glColor3bv(const GLbyte* v) {
  ::glColor3bv(v);
}

void WINAPI WGOL_GL::glColor3dv(const GLdouble* v) {
  ::glColor3dv(v);
}

void WINAPI WGOL_GL::glColor3fv(const GLfloat* v) {
  ::glColor3fv(v);
}

void WINAPI WGOL_GL::glColor3iv(const GLint* v) {
  ::glColor3iv(v);
}

void WINAPI WGOL_GL::glColor3sv(const GLshort* v) {
  ::glColor3sv(v);
}

void WINAPI WGOL_GL::glColor3ubv(const GLubyte* v) {
  ::glColor3ubv(v);
}

void WINAPI WGOL_GL::glColor3uiv(const GLuint* v) {
  ::glColor3uiv(v);
}

void WINAPI WGOL_GL::glColor3usv(const GLushort* v) {
  ::glColor3usv(v);
}

void WINAPI WGOL_GL::glColor4bv(const GLbyte* v) {
  ::glColor4bv(v);
}

void WINAPI WGOL_GL::glColor4dv(const GLdouble* v) {
  ::glColor4dv(v);
}

void WINAPI WGOL_GL::glColor4fv(const GLfloat* v) {
  ::glColor4fv(v);
}

void WINAPI WGOL_GL::glColor4iv(const GLint* v) {
  ::glColor4iv(v);
}

void WINAPI WGOL_GL::glColor4sv(const GLshort* v) {
  ::glColor4sv(v);
}

void WINAPI WGOL_GL::glColor4ubv(const GLubyte* v) {
  ::glColor4ubv(v);
}

void WINAPI WGOL_GL::glColor4uiv(const GLuint* v) {
  ::glColor4uiv(v);
}

void WINAPI WGOL_GL::glColor4usv(const GLushort* v) {
  ::glColor4usv(v);
}

void WINAPI WGOL_GL::glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
  ::glColorMask(red, green, blue, alpha);
}

void WINAPI WGOL_GL::glColorMaterial(GLenum face, GLenum mode) {
  ::glColorMaterial(face, mode);
}

void WINAPI WGOL_GL::glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) {
  ::glColorPointer(size, type, stride, pointer);
}

void WINAPI WGOL_GL::glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
  ::glCopyPixels(x, y, width, height, type);
}

void WINAPI WGOL_GL::glCopyTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border) {
  ::glCopyTexImage1D(target, level, internalFormat, x, y, width, border);
}

void WINAPI WGOL_GL::glCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
  ::glCopyTexImage2D(target, level, internalFormat, x, y, width, height, border);
}

void WINAPI WGOL_GL::glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
  ::glCopyTexSubImage1D(target, level, xoffset, x, y, width);
}

void WINAPI WGOL_GL::glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
  ::glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

void WINAPI WGOL_GL::glCullFace(GLenum mode) {
  ::glCullFace(mode);
}

void WINAPI WGOL_GL::glDeleteLists(GLuint list, GLsizei range) {
  ::glDeleteLists(list, range);
}

void WINAPI WGOL_GL::glDeleteTextures(GLsizei n, const GLuint* textures) {
  ::glDeleteTextures(n, textures);
}

void WINAPI WGOL_GL::glDepthFunc(GLenum func) {
  ::glDepthFunc(func);
}

void WINAPI WGOL_GL::glDepthMask(GLboolean flag) {
  ::glDepthMask(flag);
}

void WINAPI WGOL_GL::glDepthRange(GLclampd zNear, GLclampd zFar) {
  ::glDepthRange(zNear, zFar);
}

void WINAPI WGOL_GL::glDrawArrays(GLenum mode, GLint first, GLsizei count) {
  ::glDrawArrays(mode, first, count);
}

void WINAPI WGOL_GL::glDrawBuffer(GLenum mode) {
  ::glDrawBuffer(mode);
}

void WINAPI WGOL_GL::glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices) {
  ::glDrawElements(mode, count, type, indices);
}

void WINAPI WGOL_GL::glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels) {
  ::glDrawPixels(width, height, format, type, pixels);
}

void WINAPI WGOL_GL::glEdgeFlag(GLboolean flag) {
  ::glEdgeFlag(flag);
}

void WINAPI WGOL_GL::glEdgeFlagv(const GLboolean* flag) {
  ::glEdgeFlagv(flag);
}

void WINAPI WGOL_GL::glEdgeFlagPointer(GLsizei stride, const GLvoid* pointer) {
  ::glEdgeFlagPointer(stride, pointer);
}

void WINAPI WGOL_GL::glEnable(GLenum cap) {
  ::glEnable(cap);
}

void WINAPI WGOL_GL::glDisable(GLenum cap) {
  ::glDisable(cap);
}

void WINAPI WGOL_GL::glEnableClientState(GLenum array) {
  ::glEnableClientState(array);
}

void WINAPI WGOL_GL::glDisableClientState(GLenum array) {
  ::glDisableClientState(array);
}

void WINAPI WGOL_GL::glEvalCoord1d(GLdouble u) {
  ::glEvalCoord1d(u);
}

void WINAPI WGOL_GL::glEvalCoord1f(GLfloat u) {
  ::glEvalCoord1f(u);
}

void WINAPI WGOL_GL::glEvalCoord2d(GLdouble u, GLdouble v) {
  ::glEvalCoord2d(u, v);
}

void WINAPI WGOL_GL::glEvalCoord2f(GLfloat u, GLfloat v) {
  ::glEvalCoord2f(u, v);
}

void WINAPI WGOL_GL::glEvalCoord1dv(const GLdouble* u) {
  ::glEvalCoord1dv(u);
}

void WINAPI WGOL_GL::glEvalCoord2dv(const GLdouble* u) {
  ::glEvalCoord2dv(u);
}

void WINAPI WGOL_GL::glEvalCoord1fv(const GLfloat* u) {
  ::glEvalCoord1fv(u);
}

void WINAPI WGOL_GL::glEvalCoord2fv(const GLfloat* u) {
  ::glEvalCoord2fv(u);
}

void WINAPI WGOL_GL::glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
  ::glEvalMesh1(mode, i1, i2);
}

void WINAPI WGOL_GL::glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
  ::glEvalMesh2(mode, i1, i2, j1, j2);
}

void WINAPI WGOL_GL::glEvalPoint1(GLint i) {
  ::glEvalPoint1(i);
}

void WINAPI WGOL_GL::glEvalPoint2(GLint i, GLint j) {
  ::glEvalPoint2(i, j);
}

void WINAPI WGOL_GL::glFeedbackBuffer(GLsizei size, GLenum type, GLfloat* buffer) {
  ::glFeedbackBuffer(size, type, buffer);
}

void WINAPI WGOL_GL::glFinish() {
  ::glFinish();
}

void WINAPI WGOL_GL::glFlush() {
  ::glFlush();
}

void WINAPI WGOL_GL::glFogf(GLenum pname, GLfloat param) {
  ::glFogf(pname, param);
}

void WINAPI WGOL_GL::glFogi(GLenum pname, GLint param) {
  ::glFogi(pname, param);
}

void WINAPI WGOL_GL::glFogfv(GLenum pname, const GLfloat* params) {
  ::glFogfv(pname, params);
}

void WINAPI WGOL_GL::glFogiv(GLenum pname, const GLint* params) {
  ::glFogiv(pname, params);
}

void WINAPI WGOL_GL::glFrontFace(GLenum mode) {
  ::glFrontFace(mode);
}

void WINAPI WGOL_GL::glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
  ::glFrustum(left, right, bottom, top, zNear, zFar);
}

GLuint WINAPI WGOL_GL::glGenLists(GLsizei range) {
  return ::glGenLists(range);
}

void WINAPI WGOL_GL::glGenTextures(GLsizei n, GLuint* textures) {
  ::glGenTextures(n, textures);
}

void WINAPI WGOL_GL::glGetBooleanv(GLenum pname, GLboolean* params) {
  ::glGetBooleanv(pname, params);
}

void WINAPI WGOL_GL::glGetClipPlane(GLenum plane, GLdouble* equation) {
  ::glGetClipPlane(plane, equation);
}

void WINAPI WGOL_GL::glGetDoublev(GLenum pname, GLdouble* params) {
  ::glGetDoublev(pname, params);
}

GLenum WINAPI WGOL_GL::glGetError() {
  return ::glGetError();
}

void WINAPI WGOL_GL::glGetFloatv(GLenum pname, GLfloat* params) {
  ::glGetFloatv(pname, params);
}

void WINAPI WGOL_GL::glGetIntegerv(GLenum pname, GLint* params) {
  ::glGetIntegerv(pname, params);
}

void WINAPI WGOL_GL::glGetLightfv(GLenum light, GLenum pname, GLfloat* params) {
  ::glGetLightfv(light, pname, params);
}

void WINAPI WGOL_GL::glGetLightiv(GLenum light, GLenum pname, GLint* params) {
  ::glGetLightiv(light, pname, params);
}

void WINAPI WGOL_GL::glGetMapdv(GLenum target, GLenum query, GLdouble* v) {
  ::glGetMapdv(target, query, v);
}

void WINAPI WGOL_GL::glGetMapfv(GLenum target, GLenum query, GLfloat* v) {
  ::glGetMapfv(target, query, v);
}

void WINAPI WGOL_GL::glGetMapiv(GLenum target, GLenum query, GLint* v) {
  ::glGetMapiv(target, query, v);
}

void WINAPI WGOL_GL::glGetMaterialfv(GLenum face, GLenum pname, GLfloat* params) {
  ::glGetMaterialfv(face, pname, params);
}

void WINAPI WGOL_GL::glGetMaterialiv(GLenum face, GLenum pname, GLint* params) {
  ::glGetMaterialiv(face, pname, params);
}

void WINAPI WGOL_GL::glGetPixelMapfv(GLenum map, GLfloat* values) {
  ::glGetPixelMapfv(map, values);
}

void WINAPI WGOL_GL::glGetPixelMapuiv(GLenum map, GLuint* values) {
  ::glGetPixelMapuiv(map, values);
}

void WINAPI WGOL_GL::glGetPixelMapusv(GLenum map, GLushort* values) {
  ::glGetPixelMapusv(map, values);
}

void WINAPI WGOL_GL::glGetPointerv(GLenum pname, GLvoid** params) {
  ::glGetPointerv(pname, params);
}

void WINAPI WGOL_GL::glGetPolygonStipple(GLubyte* mask) {
  ::glGetPolygonStipple(mask);
}

const GLubyte* WINAPI WGOL_GL::glGetString(GLenum name) {
  return ::glGetString(name);
}

void WINAPI WGOL_GL::glGetTexEnvfv(GLenum target, GLenum pname, GLfloat* params) {
  ::glGetTexEnvfv(target, pname, params);
}

void WINAPI WGOL_GL::glGetTexEnviv(GLenum target, GLenum pname, GLint* params) {
  ::glGetTexEnviv(target, pname, params);
}

void WINAPI WGOL_GL::glGetTexGendv(GLenum coord, GLenum pname, GLdouble* params) {
  ::glGetTexGendv(coord, pname, params);
}

void WINAPI WGOL_GL::glGetTexGenfv(GLenum coord, GLenum pname, GLfloat* params) {
  ::glGetTexGenfv(coord, pname, params);
}

void WINAPI WGOL_GL::glGetTexGeniv(GLenum coord, GLenum pname, GLint* params) {
  ::glGetTexGeniv(coord, pname, params);
}

void WINAPI WGOL_GL::glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels) {
  ::glGetTexImage(target, level, format, type, pixels);
}

void WINAPI WGOL_GL::glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params) {
  ::glGetTexLevelParameterfv(target, level, pname, params);
}

void WINAPI WGOL_GL::glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params) {
  ::glGetTexLevelParameteriv(target, level, pname, params);
}

void WINAPI WGOL_GL::glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params) {
  ::glGetTexParameterfv(target, pname, params);
}

void WINAPI WGOL_GL::glGetTexParameteriv(GLenum target, GLenum pname, GLint* params) {
  ::glGetTexParameteriv(target, pname, params);
}

void WINAPI WGOL_GL::glHint(GLenum target, GLenum mode) {
  ::glHint(target, mode);
}

void WINAPI WGOL_GL::glIndexd(GLdouble c) {
  ::glIndexd(c);
}

void WINAPI WGOL_GL::glIndexf(GLfloat c) {
  ::glIndexf(c);
}

void WINAPI WGOL_GL::glIndexi(GLint c) {
  ::glIndexi(c);
}

void WINAPI WGOL_GL::glIndexs(GLshort c) {
  ::glIndexs(c);
}

void WINAPI WGOL_GL::glIndexdv(const GLdouble* c) {
  ::glIndexdv(c);
}

void WINAPI WGOL_GL::glIndexfv(const GLfloat* c) {
  ::glIndexfv(c);
}

void WINAPI WGOL_GL::glIndexiv(const GLint* c) {
  ::glIndexiv(c);
}

void WINAPI WGOL_GL::glIndexsv(const GLshort* c) {
  ::glIndexsv(c);
}

void WINAPI WGOL_GL::glIndexMask(GLuint mask) {
  ::glIndexMask(mask);
}

void WINAPI WGOL_GL::glIndexPointer(GLenum type, GLsizei stride, const GLvoid* pointer) {
  ::glIndexPointer(type, stride, pointer);
}

void WINAPI WGOL_GL::glInitNames() {
  ::glInitNames();
}

void WINAPI WGOL_GL::glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid* pointer) {
  ::glInterleavedArrays(format, stride, pointer);
}

GLboolean WINAPI WGOL_GL::glIsEnabled(GLenum cap) {
  return ::glIsEnabled(cap);
}

GLboolean WINAPI WGOL_GL::glIsList(GLuint list) {
  return ::glIsList(list);
}

GLboolean WINAPI WGOL_GL::glIsTexture(GLuint texture) {
  return ::glIsTexture(texture);
}

void WINAPI WGOL_GL::glLightf(GLenum light, GLenum pname, GLfloat param) {
  ::glLightf(light, pname, param);
}

void WINAPI WGOL_GL::glLighti(GLenum light, GLenum pname, GLint param) {
  ::glLighti(light, pname, param);
}

void WINAPI WGOL_GL::glLightfv(GLenum light, GLenum pname, const GLfloat* params) {
  ::glLightfv(light, pname, params);
}

void WINAPI WGOL_GL::glLightiv(GLenum light, GLenum pname, const GLint* params) {
  ::glLightiv(light, pname, params);
}

void WINAPI WGOL_GL::glLightModelf(GLenum pname, GLfloat param) {
  ::glLightModelf(pname, param);
}

void WINAPI WGOL_GL::glLightModelfv(GLenum pname, const GLfloat* params) {
  ::glLightModelfv(pname, params);
}

void WINAPI WGOL_GL::glLightModeli(GLenum pname, GLint param) {
  ::glLightModeli(pname, param);
}

void WINAPI WGOL_GL::glLightModeliv(GLenum pname, const GLint* params) {
  ::glLightModeliv(pname, params);
}

void WINAPI WGOL_GL::glLineStipple(GLint factor, GLushort pattern) {
  ::glLineStipple(factor, pattern);
}

void WINAPI WGOL_GL::glLineWidth(GLfloat width) {
  ::glLineWidth(width);
}

void WINAPI WGOL_GL::glListBase(GLuint base) {
  ::glListBase(base);
}

void WINAPI WGOL_GL::glLoadIdentity() {
  ::glLoadIdentity();
}

void WINAPI WGOL_GL::glLoadMatrixd(const GLdouble* m) {
  ::glLoadMatrixd(m);
}

void WINAPI WGOL_GL::glLoadMatrixf(const GLfloat* m) {
  ::glLoadMatrixf(m);
}

void WINAPI WGOL_GL::glLoadName(GLuint name) {
  ::glLoadName(name);
}

void WINAPI WGOL_GL::glLogicOp(GLenum opcode) {
  ::glLogicOp(opcode);
}

void WINAPI WGOL_GL::glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points) {
  ::glMap1d(target, u1, u2, stride, order, points);
}

void WINAPI WGOL_GL::glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points) {
  ::glMap1f(target, u1, u2, stride, order, points);
}

void WINAPI WGOL_GL::glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble* points) {
  ::glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void WINAPI WGOL_GL::glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat* points) {
  ::glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void WINAPI WGOL_GL::glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
  ::glMapGrid1d(un, u1, u2);
}

void WINAPI WGOL_GL::glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
  ::glMapGrid1f(un, u1, u2);
}

void WINAPI WGOL_GL::glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
  ::glMapGrid2d(un, u1, u2, vn, v1, v2);
}

void WINAPI WGOL_GL::glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
  ::glMapGrid2f(un, u1, u2, vn, v1, v2);
}

void WINAPI WGOL_GL::glMaterialf(GLenum face, GLenum pname, GLfloat param) {
  ::glMaterialf(face, pname, param);
}

void WINAPI WGOL_GL::glMateriali(GLenum face, GLenum pname, GLint param) {
  ::glMateriali(face, pname, param);
}

void WINAPI WGOL_GL::glMaterialfv(GLenum face, GLenum pname, const GLfloat* params) {
  ::glMaterialfv(face, pname, params);
}

void WINAPI WGOL_GL::glMaterialiv(GLenum face, GLenum pname, const GLint* params) {
  ::glMaterialiv(face, pname, params);
}

void WINAPI WGOL_GL::glMatrixMode(GLenum mode) {
  ::glMatrixMode(mode);
}

void WINAPI WGOL_GL::glMultMatrixd(const GLdouble* m) {
  ::glMultMatrixd(m);
}

void WINAPI WGOL_GL::glMultMatrixf(const GLfloat* m) {
  ::glMultMatrixf(m);
}

void WINAPI WGOL_GL::glNewList(GLuint list, GLenum mode) {
  ::glNewList(list, mode);
}

void WINAPI WGOL_GL::glEndList() {
  ::glEndList();
}

void WINAPI WGOL_GL::glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
  ::glNormal3b(nx, ny, nz);
}

void WINAPI WGOL_GL::glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
  ::glNormal3d(nx, ny, nz);
}

void WINAPI WGOL_GL::glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
  ::glNormal3f(nx, ny, nz);
}

void WINAPI WGOL_GL::glNormal3i(GLint nx, GLint ny, GLint nz) {
  ::glNormal3i(nx, ny, nz);
}

void WINAPI WGOL_GL::glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
  ::glNormal3s(nx, ny, nz);
}

void WINAPI WGOL_GL::glNormal3bv(const GLbyte* v) {
  ::glNormal3bv(v);
}

void WINAPI WGOL_GL::glNormal3dv(const GLdouble* v) {
  ::glNormal3dv(v);
}

void WINAPI WGOL_GL::glNormal3fv(const GLfloat* v) {
  ::glNormal3fv(v);
}

void WINAPI WGOL_GL::glNormal3iv(const GLint* v) {
  ::glNormal3iv(v);
}

void WINAPI WGOL_GL::glNormal3sv(const GLshort* v) {
  ::glNormal3sv(v);
}

void WINAPI WGOL_GL::glNormalPointer(GLenum type, GLsizei stride, const GLvoid* pointer) {
  ::glNormalPointer(type, stride, pointer);
}

void WINAPI WGOL_GL::glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
  ::glOrtho(left, right, bottom, top, zNear, zFar);
}

void WINAPI WGOL_GL::glPassThrough(GLfloat token) {
  ::glPassThrough(token);
}

void WINAPI WGOL_GL::glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat* values) {
  ::glPixelMapfv(map, mapsize, values);
}

void WINAPI WGOL_GL::glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint* values) {
  ::glPixelMapuiv(map, mapsize, values);
}

void WINAPI WGOL_GL::glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort* values) {
  ::glPixelMapusv(map, mapsize, values);
}

void WINAPI WGOL_GL::glPixelStoref(GLenum pname, GLfloat param) {
  ::glPixelStoref(pname, param);
}

void WINAPI WGOL_GL::glPixelStorei(GLenum pname, GLint param) {
  ::glPixelStorei(pname, param);
}

void WINAPI WGOL_GL::glPixelTransferf(GLenum pname, GLfloat param) {
  ::glPixelTransferf(pname, param);
}

void WINAPI WGOL_GL::glPixelTransferi(GLenum pname, GLint param) {
  ::glPixelTransferi(pname, param);
}

void WINAPI WGOL_GL::glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
  ::glPixelZoom(xfactor, yfactor);
}

void WINAPI WGOL_GL::glPointSize(GLfloat size) {
  ::glPointSize(size);
}

void WINAPI WGOL_GL::glPolygonMode(GLenum face, GLenum mode) {
  ::glPolygonMode(face, mode);
}

void WINAPI WGOL_GL::glPolygonOffset(GLfloat factor, GLfloat units) {
  ::glPolygonOffset(factor, units);
}

void WINAPI WGOL_GL::glPolygonStipple(const GLubyte* mask) {
  ::glPolygonStipple(mask);
}

void WINAPI WGOL_GL::glPrioritizeTextures(GLsizei n, const GLuint* textures, const GLclampf* priorities) {
  ::glPrioritizeTextures(n, textures, priorities);
}

void WINAPI WGOL_GL::glPushAttrib(GLbitfield mask) {
  ::glPushAttrib(mask);
}

void WINAPI WGOL_GL::glPopAttrib() {
  ::glPopAttrib();
}

void WINAPI WGOL_GL::glPushClientAttrib(GLbitfield mask) {
  ::glPushClientAttrib(mask);
}

void WINAPI WGOL_GL::glPopClientAttrib() {
  ::glPopClientAttrib();
}

void WINAPI WGOL_GL::glPushMatrix() {
  ::glPushMatrix();
}

void WINAPI WGOL_GL::glPopMatrix() {
  ::glPopMatrix();
}

void WINAPI WGOL_GL::glPushName(GLuint name) {
  ::glPushName(name);
}

void WINAPI WGOL_GL::glPopName() {
  ::glPopName();
}

void WINAPI WGOL_GL::glRasterPos2d(GLdouble x, GLdouble y) {
  ::glRasterPos2d(x, y);
}

void WINAPI WGOL_GL::glRasterPos2f(GLfloat x, GLfloat y) {
  ::glRasterPos2f(x, y);
}

void WINAPI WGOL_GL::glRasterPos2i(GLint x, GLint y) {
  ::glRasterPos2i(x, y);
}

void WINAPI WGOL_GL::glRasterPos2s(GLshort x, GLshort y) {
  ::glRasterPos2s(x, y);
}

void WINAPI WGOL_GL::glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
  ::glRasterPos3d(x, y, z);
}

void WINAPI WGOL_GL::glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
  ::glRasterPos3f(x, y, z);
}

void WINAPI WGOL_GL::glRasterPos3i(GLint x, GLint y, GLint z) {
  ::glRasterPos3i(x, y, z);
}

void WINAPI WGOL_GL::glRasterPos3s(GLshort x, GLshort y, GLshort z) {
  ::glRasterPos3s(x, y, z);
}

void WINAPI WGOL_GL::glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
  ::glRasterPos4d(x, y, z, w);
}

void WINAPI WGOL_GL::glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
  ::glRasterPos4f(x, y, z, w);
}

void WINAPI WGOL_GL::glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
  ::glRasterPos4i(x, y, z, w);
}

void WINAPI WGOL_GL::glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
  ::glRasterPos4s(x, y, z, w);
}

void WINAPI WGOL_GL::glRasterPos2dv(const GLdouble* v) {
  ::glRasterPos2dv(v);
}

void WINAPI WGOL_GL::glRasterPos2fv(const GLfloat* v) {
  ::glRasterPos2fv(v);
}

void WINAPI WGOL_GL::glRasterPos2iv(const GLint* v) {
  ::glRasterPos2iv(v);
}

void WINAPI WGOL_GL::glRasterPos2sv(const GLshort* v) {
  ::glRasterPos2sv(v);
}

void WINAPI WGOL_GL::glRasterPos3dv(const GLdouble* v) {
  ::glRasterPos3dv(v);
}

void WINAPI WGOL_GL::glRasterPos3fv(const GLfloat* v) {
  ::glRasterPos3fv(v);
}

void WINAPI WGOL_GL::glRasterPos3iv(const GLint* v) {
  ::glRasterPos3iv(v);
}

void WINAPI WGOL_GL::glRasterPos3sv(const GLshort* v) {
  ::glRasterPos3sv(v);
}

void WINAPI WGOL_GL::glRasterPos4dv(const GLdouble* v) {
  ::glRasterPos4dv(v);
}

void WINAPI WGOL_GL::glRasterPos4fv(const GLfloat* v) {
  ::glRasterPos4fv(v);
}

void WINAPI WGOL_GL::glRasterPos4iv(const GLint* v) {
  ::glRasterPos4iv(v);
}

void WINAPI WGOL_GL::glRasterPos4sv(const GLshort* v) {
  ::glRasterPos4sv(v);
}

void WINAPI WGOL_GL::glReadBuffer(GLenum mode) {
  ::glReadBuffer(mode);
}

void WINAPI WGOL_GL::glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels) {
  ::glReadPixels(x, y, width, height, format, type, pixels);
}

void WINAPI WGOL_GL::glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
  ::glRectd(x1, y1, x2, y2);
}

void WINAPI WGOL_GL::glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
  ::glRectf(x1, y1, x2, y2);
}

void WINAPI WGOL_GL::glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
  ::glRecti(x1, y1, x2, y2);
}

void WINAPI WGOL_GL::glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
  ::glRects(x1, y1, x2, y2);
}

void WINAPI WGOL_GL::glRectdv(const GLdouble* v1, const GLdouble* v2) {
  ::glRectdv(v1, v2);
}

void WINAPI WGOL_GL::glRectfv(const GLfloat* v1, const GLfloat* v2) {
  ::glRectfv(v1, v2);
}

void WINAPI WGOL_GL::glRectiv(const GLint* v1, const GLint* v2) {
  ::glRectiv(v1, v2);
}

void WINAPI WGOL_GL::glRectsv(const GLshort* v1, const GLshort* v2) {
  ::glRectsv(v1, v2);
}

GLint WINAPI WGOL_GL::glRenderMode(GLenum mode) {
  return ::glRenderMode(mode);
}

void WINAPI WGOL_GL::glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
  ::glRotated(angle, x, y, z);
}

void WINAPI WGOL_GL::glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
  ::glRotatef(angle, x, y, z);
}

void WINAPI WGOL_GL::glScaled(GLdouble x, GLdouble y, GLdouble z) {
  ::glScaled(x, y, z);
}

void WINAPI WGOL_GL::glScalef(GLfloat x, GLfloat y, GLfloat z) {
  ::glScalef(x, y, z);
}

void WINAPI WGOL_GL::glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
  ::glScissor(x, y, width, height);
}

void WINAPI WGOL_GL::glSelectBuffer(GLsizei size, GLuint* buffer) {
  ::glSelectBuffer(size, buffer);
}

void WINAPI WGOL_GL::glShadeModel(GLenum mode) {
  ::glShadeModel(mode);
}

void WINAPI WGOL_GL::glStencilFunc(GLenum func, GLint ref, GLuint mask) {
  ::glStencilFunc(func, ref, mask);
}

void WINAPI WGOL_GL::glStencilMask(GLuint mask) {
  ::glStencilMask(mask);
}

void WINAPI WGOL_GL::glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
  ::glStencilOp(fail, zfail, zpass);
}

void WINAPI WGOL_GL::glTexCoord1d(GLdouble s) {
  ::glTexCoord1d(s);
}

void WINAPI WGOL_GL::glTexCoord1f(GLfloat s) {
  ::glTexCoord1f(s);
}

void WINAPI WGOL_GL::glTexCoord1i(GLint s) {
  ::glTexCoord1i(s);
}

void WINAPI WGOL_GL::glTexCoord1s(GLshort s) {
  ::glTexCoord1s(s);
}

void WINAPI WGOL_GL::glTexCoord2d(GLdouble s, GLdouble t) {
  ::glTexCoord2d(s, t);
}

void WINAPI WGOL_GL::glTexCoord2f(GLfloat s, GLfloat t) {
  ::glTexCoord2f(s, t);
}

void WINAPI WGOL_GL::glTexCoord2i(GLint s, GLint t) {
  ::glTexCoord2i(s, t);
}

void WINAPI WGOL_GL::glTexCoord2s(GLshort s, GLshort t) {
  ::glTexCoord2s(s, t);
}

void WINAPI WGOL_GL::glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
  ::glTexCoord3d(s, t, r);
}

void WINAPI WGOL_GL::glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
  ::glTexCoord3f(s, t, r);
}

void WINAPI WGOL_GL::glTexCoord3i(GLint s, GLint t, GLint r) {
  ::glTexCoord3i(s, t, r);
}

void WINAPI WGOL_GL::glTexCoord3s(GLshort s, GLshort t, GLshort r) {
  ::glTexCoord3s(s, t, r);
}

void WINAPI WGOL_GL::glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
  ::glTexCoord4d(s, t, r, q);
}

void WINAPI WGOL_GL::glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
  ::glTexCoord4f(s, t, r, q);
}

void WINAPI WGOL_GL::glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
  ::glTexCoord4i(s, t, r, q);
}

void WINAPI WGOL_GL::glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
  ::glTexCoord4s(s, t, r, q);
}

void WINAPI WGOL_GL::glTexCoord1dv(const GLdouble* v) {
  ::glTexCoord1dv(v);
}

void WINAPI WGOL_GL::glTexCoord1fv(const GLfloat* v) {
  ::glTexCoord1fv(v);
}

void WINAPI WGOL_GL::glTexCoord1iv(const GLint* v) {
  ::glTexCoord1iv(v);
}

void WINAPI WGOL_GL::glTexCoord1sv(const GLshort* v) {
  ::glTexCoord1sv(v);
}

void WINAPI WGOL_GL::glTexCoord2dv(const GLdouble* v) {
  ::glTexCoord2dv(v);
}

void WINAPI WGOL_GL::glTexCoord2fv(const GLfloat* v) {
  ::glTexCoord2fv(v);
}

void WINAPI WGOL_GL::glTexCoord2iv(const GLint* v) {
  ::glTexCoord2iv(v);
}

void WINAPI WGOL_GL::glTexCoord2sv(const GLshort* v) {
  ::glTexCoord2sv(v);
}

void WINAPI WGOL_GL::glTexCoord3dv(const GLdouble* v) {
  ::glTexCoord3dv(v);
}

void WINAPI WGOL_GL::glTexCoord3fv(const GLfloat* v) {
  ::glTexCoord3fv(v);
}

void WINAPI WGOL_GL::glTexCoord3iv(const GLint* v) {
  ::glTexCoord3iv(v);
}

void WINAPI WGOL_GL::glTexCoord3sv(const GLshort* v) {
  ::glTexCoord3sv(v);
}

void WINAPI WGOL_GL::glTexCoord4dv(const GLdouble* v) {
  ::glTexCoord4dv(v);
}

void WINAPI WGOL_GL::glTexCoord4fv(const GLfloat* v) {
  ::glTexCoord4fv(v);
}

void WINAPI WGOL_GL::glTexCoord4iv(const GLint* v) {
  ::glTexCoord4iv(v);
}

void WINAPI WGOL_GL::glTexCoord4sv(const GLshort* v) {
  ::glTexCoord4sv(v);
}

void WINAPI WGOL_GL::glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) {
  ::glTexCoordPointer(size, type, stride, pointer);
}

void WINAPI WGOL_GL::glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
  ::glTexEnvf(target, pname, param);
}

void WINAPI WGOL_GL::glTexEnvi(GLenum target, GLenum pname, GLint param) {
  ::glTexEnvi(target, pname, param);
}

void WINAPI WGOL_GL::glTexEnvfv(GLenum target, GLenum pname, const GLfloat* params) {
  ::glTexEnvfv(target, pname, params);
}

void WINAPI WGOL_GL::glTexEnviv(GLenum target, GLenum pname, const GLint* params) {
  ::glTexEnviv(target, pname, params);
}

void WINAPI WGOL_GL::glTexGend(GLenum coord, GLenum pname, GLdouble param) {
  ::glTexGend(coord, pname, param);
}

void WINAPI WGOL_GL::glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
  ::glTexGenf(coord, pname, param);
}

void WINAPI WGOL_GL::glTexGeni(GLenum coord, GLenum pname, GLint param) {
  ::glTexGeni(coord, pname, param);
}

void WINAPI WGOL_GL::glTexGendv(GLenum coord, GLenum pname, const GLdouble* params) {
  ::glTexGendv(coord, pname, params);
}

void WINAPI WGOL_GL::glTexGenfv(GLenum coord, GLenum pname, const GLfloat* params) {
  ::glTexGenfv(coord, pname, params);
}

void WINAPI WGOL_GL::glTexGeniv(GLenum coord, GLenum pname, const GLint* params) {
  ::glTexGeniv(coord, pname, params);
}

void WINAPI WGOL_GL::glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLint format, GLenum type, const GLvoid* pixels) {
  ::glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
}

void WINAPI WGOL_GL::glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLint format, GLenum type, const GLvoid* pixels) {
  ::glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

void WINAPI WGOL_GL::glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
  ::glTexParameterf(target, pname, param);
}

void WINAPI WGOL_GL::glTexParameteri(GLenum target, GLenum pname, GLint param) {
  ::glTexParameteri(target, pname, param);
}

void WINAPI WGOL_GL::glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params) {
  ::glTexParameterfv(target, pname, params);
}

void WINAPI WGOL_GL::glTexParameteriv(GLenum target, GLenum pname, const GLint* params) {
  ::glTexParameteriv(target, pname, params);
}

void WINAPI WGOL_GL::glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels) {
  ::glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
}

void WINAPI WGOL_GL::glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels) {
  ::glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void WINAPI WGOL_GL::glTranslated(GLdouble x, GLdouble y, GLdouble z) {
  ::glTranslated(x, y, z);
}

void WINAPI WGOL_GL::glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
  ::glTranslatef(x, y, z);
}

void WINAPI WGOL_GL::glVertex2d(GLdouble x, GLdouble y) {
  ::glVertex2d(x, y);
}

void WINAPI WGOL_GL::glVertex2f(GLfloat x, GLfloat y) {
  ::glVertex2f(x, y);
}

void WINAPI WGOL_GL::glVertex2i(GLint x, GLint y) {
  ::glVertex2i(x, y);
}

void WINAPI WGOL_GL::glVertex2s(GLshort x, GLshort y) {
  ::glVertex2s(x, y);
}

void WINAPI WGOL_GL::glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
  ::glVertex3d(x, y, z);
}

void WINAPI WGOL_GL::glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
  ::glVertex3f(x, y, z);
}

void WINAPI WGOL_GL::glVertex3i(GLint x, GLint y, GLint z) {
  ::glVertex3i(x, y, z);
}

void WINAPI WGOL_GL::glVertex3s(GLshort x, GLshort y, GLshort z) {
  ::glVertex3s(x, y, z);
}

void WINAPI WGOL_GL::glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
  ::glVertex4d(x, y, z, w);
}

void WINAPI WGOL_GL::glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
  ::glVertex4f(x, y, z, w);
}

void WINAPI WGOL_GL::glVertex4i(GLint x, GLint y, GLint z, GLint w) {
  ::glVertex4i(x, y, z, w);
}

void WINAPI WGOL_GL::glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
  ::glVertex4s(x, y, z, w);
}

void WINAPI WGOL_GL::glVertex2dv(const GLdouble* v) {
  ::glVertex2dv(v);
}

void WINAPI WGOL_GL::glVertex2fv(const GLfloat* v) {
  ::glVertex2fv(v);
}

void WINAPI WGOL_GL::glVertex2iv(const GLint* v) {
  ::glVertex2iv(v);
}

void WINAPI WGOL_GL::glVertex2sv(const GLshort* v) {
  ::glVertex2sv(v);
}

void WINAPI WGOL_GL::glVertex3dv(const GLdouble* v) {
  ::glVertex3dv(v);
}

void WINAPI WGOL_GL::glVertex3fv(const GLfloat* v) {
  ::glVertex3fv(v);
}

void WINAPI WGOL_GL::glVertex3iv(const GLint* v) {
  ::glVertex3iv(v);
}

void WINAPI WGOL_GL::glVertex3sv(const GLshort* v) {
  ::glVertex3sv(v);
}

void WINAPI WGOL_GL::glVertex4dv(const GLdouble* v) {
  ::glVertex4dv(v);
}

void WINAPI WGOL_GL::glVertex4fv(const GLfloat* v) {
  ::glVertex4fv(v);
}

void WINAPI WGOL_GL::glVertex4iv(const GLint* v) {
  ::glVertex4iv(v);
}

void WINAPI WGOL_GL::glVertex4sv(const GLshort* v) {
  ::glVertex4sv(v);
}

void WINAPI WGOL_GL::glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) {
  ::glVertexPointer(size, type, stride, pointer);
}

void WINAPI WGOL_GL::glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
  ::glViewport(x, y, width, height);
}
