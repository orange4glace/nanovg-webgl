type int = number;
type float = number;
type paint_t = number;
type image_t = number;
type unsigned_byte = number;

declare namespace NVGType {
  type int = number;
  type float = number;
  type paint_t = number;
  type image_t = number;
  type uintptr_t = BigInt;
  type unsigned_byte = number;
}

interface NVG {
  gl: WebGLRenderingContext;
  // void nvgBeginFrame(NVGcontext* ctx, float windowWidth, float windowHeight, float devicePixelRatio);
  beginFrame(width: float, height: float, ratio: float): void;
  // void nvgCancelFrame(NVGcontext* ctx);
  // void nvgEndFrame(NVGcontext* ctx);
  endFrame(): void;
  // void nvgGlobalCompositeOperation(NVGcontext* ctx, int op);
  globalCompositeOperation(op: GLenum);
  // void nvgGlobalCompositeBlendFunc(NVGcontext* ctx, int sfactor, int dfactor);
  globalCompositeBlendFunc(sfactor: GLenum, dfactor: GLenum);
  // void nvgGlobalCompositeBlendFuncSeparate(NVGcontext* ctx, int srcRGB, int dstRGB, int srcAlpha, int dstAlpha);
  globalCompositeBlendFuncSeparate(srcRGB: GLenum, dstRGB: GLenum, srcAlpha: GLenum, dstAlpha: GLenum);
  // void nvgBlendEquation(NVGcontext* ctx, int mode);
  blendEquation(mode: GLenum);
  // void nvgBlendEquationSeparate(NVGcontext* ctx, int modeRGB, int modeAlpha);
  blendEquationSeparate(modeRGB: GLenum, modeAlpha: GLenum);
  // NVGcolor nvgRGB(unsigned char r, unsigned char g, unsigned char b);
  // NVGcolor nvgRGBf(float r, float g, float b);
  // NVGcolor nvgRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
  // NVGcolor nvgRGBAf(float r, float g, float b, float a);
  // NVGcolor nvgLerpRGBA(NVGcolor c0, NVGcolor c1, float u);
  // NVGcolor nvgTransRGBA(NVGcolor c0, unsigned char a);
  // NVGcolor nvgTransRGBAf(NVGcolor c0, float a);
  // NVGcolor nvgHSL(float h, float s, float l);
  // NVGcolor nvgHSLA(float h, float s, float l, unsigned char a);
  // void nvgSave(NVGcontext* ctx);
  save(): void;
  // void nvgRestore(NVGcontext* ctx);
  restore(): void;
  // void nvgReset(NVGcontext* ctx);
  // void nvgShapeAntiAlias(NVGcontext* ctx, int enabled);
  // void nvgStrokeColor(NVGcontext* ctx, NVGcolor color);
  strokeColor(r: unsigned_byte, g: unsigned_byte, b: unsigned_byte, a: unsigned_byte): void;
  // void nvgStrokePaint(NVGcontext* ctx, NVGpaint paint);
  // void nvgFillColor(NVGcontext* ctx, NVGcolor color);
  fillColor(r: unsigned_byte, g: unsigned_byte, b: unsigned_byte, a: unsigned_byte): void;
  // void nvgFillPaint(NVGcontext* ctx, NVGpaint paint);
  fillPaint(paint: paint_t): void;
  // void nvgMiterLimit(NVGcontext* ctx, float limit);
  // void nvgStrokeWidth(NVGcontext* ctx, float size);
  // void nvgLineCap(NVGcontext* ctx, int cap);
  // void nvgLineJoin(NVGcontext* ctx, int join);
  // void nvgGlobalAlpha(NVGcontext* ctx, float alpha);
  // void nvgResetTransform(NVGcontext* ctx);
  // void nvgTransform(NVGcontext* ctx, float a, float b, float c, float d, float e, float f);
  // void nvgTranslate(NVGcontext* ctx, float x, float y);
  translate(x: float, y: float): void;
  // void nvgRotate(NVGcontext* ctx, float angle);
  rotate(r: float): void;
  // void nvgSkewX(NVGcontext* ctx, float angle);
  // void nvgSkewY(NVGcontext* ctx, float angle);
  // void nvgScale(NVGcontext* ctx, float x, float y);
  scale(x: float, y: float): void;
  // void nvgCurrentTransform(NVGcontext* ctx, float* xform);
  // void nvgTransformIdentity(float* dst);
  // void nvgTransformTranslate(float* dst, float tx, float ty);
  // void nvgTransformScale(float* dst, float sx, float sy);
  // void nvgTransformRotate(float* dst, float a);
  // void nvgTransformSkewX(float* dst, float a);
  // void nvgTransformSkewY(float* dst, float a);
  // void nvgTransformMultiply(float* dst, const float* src);
  // void nvgTransformPremultiply(float* dst, const float* src);
  // int nvgTransformInverse(float* dst, const float* src);
  // void nvgTransformPoint(float* dstx, float* dsty, const float* xform, float srcx, float srcy);
  // float nvgDegToRad(float deg);
  // float nvgRadToDeg(float rad);
  // int nvgCreateImage(NVGcontext* ctx, const char* filename, int imageFlags);
  // int nvgCreateImageMem(NVGcontext* ctx, int imageFlags, unsigned char* data, int ndata);
  // int nvgCreateImageRGBA(NVGcontext* ctx, int w, int h, int imageFlags, const unsigned char* data);
  createImageRGBA(w: float, h: float, flag: int, ptr: BigInt): image_t;
  // int nvgCreateImageRGBA2(NVGcontext* ctx, int w, int h, int imageFlags, const unsigned char* data);
  // void nvgUpdateImage(NVGcontext* ctx, int image, const unsigned char* data);
  // void nvgImageSize(NVGcontext* ctx, int image, int* w, int* h);
  // void nvgDeleteImage(NVGcontext* ctx, int image);
  deleteImage(image: image_t): void;
  // NVGpaint nvgLinearGradient(NVGcontext* ctx, float sx, float sy, float ex, float ey,
  //             NVGcolor icol, NVGcolor ocol);
  // NVGpaint nvgBoxGradient(NVGcontext* ctx, float x, float y, float w, float h,
  //         float r, float f, NVGcolor icol, NVGcolor ocol);
  // NVGpaint nvgRadialGradient(NVGcontext* ctx, float cx, float cy, float inr, float outr,
  //             NVGcolor icol, NVGcolor ocol);
  // NVGpaint nvgImagePattern(NVGcontext* ctx, float ox, float oy, float ex, float ey,
  //           float angle, int image, float alpha);
  imagePattern(ox: float, oy: float, ex: float, ey: float, angle: float, paint: paint_t, alpha: float): number;
  // void nvgScissor(NVGcontext* ctx, float x, float y, float w, float h);
  // void nvgIntersectScissor(NVGcontext* ctx, float x, float y, float w, float h);
  // void nvgResetScissor(NVGcontext* ctx);
  // void nvgBeginPath(NVGcontext* ctx);
  beginPath(): void;
  // void nvgMoveTo(NVGcontext* ctx, float x, float y);
  moveTo(x: float, y: float): void;
  // void nvgLineTo(NVGcontext* ctx, float x, float y);
  lineTo(x: float, y: float): void;
  // void nvgBezierTo(NVGcontext* ctx, float c1x, float c1y, float c2x, float c2y, float x, float y);
  // void nvgQuadTo(NVGcontext* ctx, float cx, float cy, float x, float y);
  // void nvgArcTo(NVGcontext* ctx, float x1, float y1, float x2, float y2, float radius);
  // void nvgClosePath(NVGcontext* ctx);
  closePath(): void;
  // void nvgPathWinding(NVGcontext* ctx, int dir);
  // void nvgArc(NVGcontext* ctx, float cx, float cy, float r, float a0, float a1, int dir);
  // void nvgRect(NVGcontext* ctx, float x, float y, float w, float h);
  // void nvgRoundedRect(NVGcontext* ctx, float x, float y, float w, float h, float r);
  // void nvgRoundedRectVarying(NVGcontext* ctx, float x, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft);
  // void nvgEllipse(NVGcontext* ctx, float cx, float cy, float rx, float ry);
  // void nvgCircle(NVGcontext* ctx, float cx, float cy, float r);
  // void nvgFill(NVGcontext* ctx);
  fill(): void;
  // void nvgStroke(NVGcontext* ctx);
  stroke(): void;
  // int nvgCreateFont(NVGcontext* ctx, const char* name, const char* filename);
  // int nvgCreateFontMem(NVGcontext* ctx, const char* name, unsigned char* data, int ndata, int freeData);
  // int nvgFindFont(NVGcontext* ctx, const char* name);
  // int nvgAddFallbackFontId(NVGcontext* ctx, int baseFont, int fallbackFont);
  // int nvgAddFallbackFont(NVGcontext* ctx, const char* baseFont, const char* fallbackFont);
  // void nvgFontSize(NVGcontext* ctx, float size);
  // void nvgFontBlur(NVGcontext* ctx, float blur);
  // void nvgTextLetterSpacing(NVGcontext* ctx, float spacing);
  // void nvgTextLineHeight(NVGcontext* ctx, float lineHeight);
  // void nvgTextAlign(NVGcontext* ctx, int align);
  // void nvgFontFaceId(NVGcontext* ctx, int font);
  // void nvgFontFace(NVGcontext* ctx, const char* font);
  // float nvgText(NVGcontext* ctx, float x, float y, const char* string, const char* end);
  // void nvgTextBox(NVGcontext* ctx, float x, float y, float breakRowWidth, const char* string, const char* end);
  // float nvgTextBounds(NVGcontext* ctx, float x, float y, const char* string, const char* end, float* bounds);
  // void nvgTextBoxBounds(NVGcontext* ctx, float x, float y, float breakRowWidth, const char* string, const char* end, float* bounds);
  // int nvgTextGlyphPositions(NVGcontext* ctx, float x, float y, const char* string, const char* end, NVGglyphPosition* positions, int maxPositions);
  // void nvgTextMetrics(NVGcontext* ctx, float* ascender, float* descender, float* lineh);
  // int nvgTextBreakLines(NVGcontext* ctx, const char* string, const char* end, float breakRowWidth, NVGtextRow* rows, int maxRows);

  freePaint(paint: paint_t): void;
}

export default NVG;

export {
  NVGType
}