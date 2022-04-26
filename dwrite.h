//+--------------------------------------------------------------------------
//
//  Copyright (c) Microsoft Corporation.  All rights reserved.
//
//  Abstract:
//     DirectX Typography Services public API definitions.
//
//----------------------------------------------------------------------------

/* This header has been (heavily) modified for C compatibility.
If you're using C++ consider using the unmodified version in the Win32 API.
-Tom Arnesen */

#ifndef DWRITE_H_INCLUDED
#define DWRITE_H_INCLUDED

#pragma once

#ifndef DWRITE_NO_WINDOWS_H

#include <specstrings.h>
#include <unknwn.h>

#endif // DWRITE_NO_WINDOWS_H

#include <dcommon.h>

#ifndef DWRITE_DECLARE_INTERFACE
#define DWRITE_DECLARE_INTERFACE(iid) DECLSPEC_UUID(iid) DECLSPEC_NOVTABLE
#endif

#ifndef DWRITE_EXPORT
#define DWRITE_EXPORT __declspec(dllimport) WINAPI
#endif

#ifdef __cplusplus
#error This DirectWrite header has been modified for C compatibility. If you're using C++ consider using the unmodified version in the Win32 API.
#endif


/* Typedeffed interfaces */

typedef interface IDWriteFontFileLoader IDWriteFontFileLoader;
typedef interface IDWriteLocalFontFileLoader IDWriteLocalFontFileLoader;
typedef interface IDWriteFontFileStream IDWriteFontFileStream;
typedef interface IDWriteFontFile IDWriteFontFile;
typedef interface IDWriteRenderingParams IDWriteRenderingParams;
typedef interface IDWriteFontFace IDWriteFontFace;
typedef interface IDWriteFontCollectionLoader IDWriteFontCollectionLoader;
typedef interface IDWriteFontFileEnumerator IDWriteFontFileEnumerator;
typedef interface IDWriteLocalizedStrings IDWriteLocalizedStrings;
typedef interface IDWriteFontCollection IDWriteFontCollection;
typedef interface IDWriteFontList IDWriteFontList;
typedef interface IDWriteFontFamily IDWriteFontFamily;
typedef interface IDWriteFont IDWriteFont;
typedef interface IDWriteTextFormat IDWriteTextFormat;
typedef interface IDWriteTypography IDWriteTypography;
typedef interface IDWriteNumberSubstitution IDWriteNumberSubstitution;
typedef interface IDWriteTextAnalysisSource IDWriteTextAnalysisSource;
typedef interface IDWriteTextAnalysisSink IDWriteTextAnalysisSink;
typedef interface IDWriteTextAnalyzer IDWriteTextAnalyzer;
typedef interface IDWriteInlineObject IDWriteInlineObject;
typedef interface IDWritePixelSnapping IDWritePixelSnapping;
typedef interface IDWriteTextRenderer IDWriteTextRenderer;
typedef interface IDWriteTextLayout IDWriteTextLayout;
typedef interface IDWriteBitmapRenderTarget IDWriteBitmapRenderTarget;
typedef interface IDWriteGdiInterop IDWriteGdiInterop;
typedef interface IDWriteGlyphRunAnalysis IDWriteGlyphRunAnalysis;
typedef interface IDWriteFactory IDWriteFactory;


/* Interface GUIDs */

extern const IID IID_IDWriteFontFileLoader;
extern const IID IID_IDWriteLocalFontFileLoader;
extern const IID IID_IDWriteFontFileStream;
extern const IID IID_IDWriteFontFile;
extern const IID IID_IDWriteRenderingParams;
extern const IID IID_IDWriteFontFace;
extern const IID IID_IDWriteFontCollectionLoader;
extern const IID IID_IDWriteFontFileEnumerator;
extern const IID IID_IDWriteLocalizedStrings;
extern const IID IID_IDWriteFontCollection;
extern const IID IID_IDWriteFontList;
extern const IID IID_IDWriteFontFamily;
extern const IID IID_IDWriteFont;
extern const IID IID_IDWriteTextFormat;
extern const IID IID_IDWriteTypography;
extern const IID IID_IDWriteNumberSubstitution;
extern const IID IID_IDWriteTextAnalysisSource;
extern const IID IID_IDWriteTextAnalysisSink;
extern const IID IID_IDWriteTextAnalyzer;
extern const IID IID_IDWriteInlineObject;
extern const IID IID_IDWritePixelSnapping;
extern const IID IID_IDWriteTextRenderer;
extern const IID IID_IDWriteTextLayout;
extern const IID IID_IDWriteBitmapRenderTarget;
extern const IID IID_IDWriteGdiInterop;
extern const IID IID_IDWriteGlyphRunAnalysis;
extern const IID IID_IDWriteFactory;


/// <summary>
/// The type of a font represented by a single font file.
/// Font formats that consist of multiple files, e.g. Type 1 .PFM and .PFB, have
/// separate enum values for each of the file type.
/// </summary>
typedef enum DWRITE_FONT_FILE_TYPE {
	/// <summary>
	/// Font type is not recognized by the DirectWrite font system.
	/// </summary>
	DWRITE_FONT_FILE_TYPE_UNKNOWN,

	/// <summary>
	/// OpenType font with CFF outlines.
	/// </summary>
	DWRITE_FONT_FILE_TYPE_CFF,

	/// <summary>
	/// OpenType font with TrueType outlines.
	/// </summary>
	DWRITE_FONT_FILE_TYPE_TRUETYPE,

	/// <summary>
	/// OpenType font that contains a TrueType collection.
	/// </summary>
	DWRITE_FONT_FILE_TYPE_OPENTYPE_COLLECTION,

	/// <summary>
	/// Type 1 PFM font.
	/// </summary>
	DWRITE_FONT_FILE_TYPE_TYPE1_PFM,

	/// <summary>
	/// Type 1 PFB font.
	/// </summary>
	DWRITE_FONT_FILE_TYPE_TYPE1_PFB,

	/// <summary>
	/// Vector .FON font.
	/// </summary>
	DWRITE_FONT_FILE_TYPE_VECTOR,

	/// <summary>
	/// Bitmap .FON font.
	/// </summary>
	DWRITE_FONT_FILE_TYPE_BITMAP,

	// The following name is obsolete, but kept as an alias to avoid breaking existing code.
	DWRITE_FONT_FILE_TYPE_TRUETYPE_COLLECTION = DWRITE_FONT_FILE_TYPE_OPENTYPE_COLLECTION,
} DWRITE_FONT_FILE_TYPE;

/// <summary>
/// The file format of a complete font face.
/// Font formats that consist of multiple files, e.g. Type 1 .PFM and .PFB, have
/// a single enum entry.
/// </summary>
typedef enum DWRITE_FONT_FACE_TYPE {
	/// <summary>
	/// OpenType font face with CFF outlines.
	/// </summary>
	DWRITE_FONT_FACE_TYPE_CFF,

	/// <summary>
	/// OpenType font face with TrueType outlines.
	/// </summary>
	DWRITE_FONT_FACE_TYPE_TRUETYPE,

	/// <summary>
	/// OpenType font face that is a part of a TrueType or CFF collection.
	/// </summary>
	DWRITE_FONT_FACE_TYPE_OPENTYPE_COLLECTION,

	/// <summary>
	/// A Type 1 font face.
	/// </summary>
	DWRITE_FONT_FACE_TYPE_TYPE1,

	/// <summary>
	/// A vector .FON format font face.
	/// </summary>
	DWRITE_FONT_FACE_TYPE_VECTOR,

	/// <summary>
	/// A bitmap .FON format font face.
	/// </summary>
	DWRITE_FONT_FACE_TYPE_BITMAP,

	/// <summary>
	/// Font face type is not recognized by the DirectWrite font system.
	/// </summary>
	DWRITE_FONT_FACE_TYPE_UNKNOWN,

	/// <summary>
	/// The font data includes only the CFF table from an OpenType CFF font.
	/// This font face type can be used only for embedded fonts (i.e., custom
	/// font file loaders) and the resulting font face object supports only the
	/// minimum functionality necessary to render glyphs.
	/// </summary>
	DWRITE_FONT_FACE_TYPE_RAW_CFF,

	// The following name is obsolete, but kept as an alias to avoid breaking existing code.
	DWRITE_FONT_FACE_TYPE_TRUETYPE_COLLECTION = DWRITE_FONT_FACE_TYPE_OPENTYPE_COLLECTION,
} DWRITE_FONT_FACE_TYPE;

/// <summary>
/// Specifies algorithmic style simulations to be applied to the font face.
/// Bold and oblique simulations can be combined via bitwise OR operation.
/// </summary>
typedef enum DWRITE_FONT_SIMULATIONS {
	/// <summary>
	/// No simulations are performed.
	/// </summary>
	DWRITE_FONT_SIMULATIONS_NONE = 0x0000,

	/// <summary>
	/// Algorithmic emboldening is performed.
	/// </summary>
	DWRITE_FONT_SIMULATIONS_BOLD = 0x0001,

	/// <summary>
	/// Algorithmic italicization is performed.
	/// </summary>
	DWRITE_FONT_SIMULATIONS_OBLIQUE = 0x0002
} DWRITE_FONT_SIMULATIONS;

#ifdef DEFINE_ENUM_FLAG_OPERATORS
DEFINE_ENUM_FLAG_OPERATORS(DWRITE_FONT_SIMULATIONS);
#endif

/// <summary>
/// The font weight enumeration describes common values for degree of blackness or thickness of strokes of characters in a font.
/// Font weight values less than 1 or greater than 999 are considered to be invalid, and they are rejected by font API functions.
/// </summary>
typedef enum DWRITE_FONT_WEIGHT {
	/// <summary>
	/// Predefined font weight : Thin (100).
	/// </summary>
	DWRITE_FONT_WEIGHT_THIN = 100,

	/// <summary>
	/// Predefined font weight : Extra-light (200).
	/// </summary>
	DWRITE_FONT_WEIGHT_EXTRA_LIGHT = 200,

	/// <summary>
	/// Predefined font weight : Ultra-light (200).
	/// </summary>
	DWRITE_FONT_WEIGHT_ULTRA_LIGHT = 200,

	/// <summary>
	/// Predefined font weight : Light (300).
	/// </summary>
	DWRITE_FONT_WEIGHT_LIGHT = 300,

	/// <summary>
	/// Predefined font weight : Semi-light (350).
	/// </summary>
	DWRITE_FONT_WEIGHT_SEMI_LIGHT = 350,

	/// <summary>
	/// Predefined font weight : Normal (400).
	/// </summary>
	DWRITE_FONT_WEIGHT_NORMAL = 400,

	/// <summary>
	/// Predefined font weight : Regular (400).
	/// </summary>
	DWRITE_FONT_WEIGHT_REGULAR = 400,

	/// <summary>
	/// Predefined font weight : Medium (500).
	/// </summary>
	DWRITE_FONT_WEIGHT_MEDIUM = 500,

	/// <summary>
	/// Predefined font weight : Demi-bold (600).
	/// </summary>
	DWRITE_FONT_WEIGHT_DEMI_BOLD = 600,

	/// <summary>
	/// Predefined font weight : Semi-bold (600).
	/// </summary>
	DWRITE_FONT_WEIGHT_SEMI_BOLD = 600,

	/// <summary>
	/// Predefined font weight : Bold (700).
	/// </summary>
	DWRITE_FONT_WEIGHT_BOLD = 700,

	/// <summary>
	/// Predefined font weight : Extra-bold (800).
	/// </summary>
	DWRITE_FONT_WEIGHT_EXTRA_BOLD = 800,

	/// <summary>
	/// Predefined font weight : Ultra-bold (800).
	/// </summary>
	DWRITE_FONT_WEIGHT_ULTRA_BOLD = 800,

	/// <summary>
	/// Predefined font weight : Black (900).
	/// </summary>
	DWRITE_FONT_WEIGHT_BLACK = 900,

	/// <summary>
	/// Predefined font weight : Heavy (900).
	/// </summary>
	DWRITE_FONT_WEIGHT_HEAVY = 900,

	/// <summary>
	/// Predefined font weight : Extra-black (950).
	/// </summary>
	DWRITE_FONT_WEIGHT_EXTRA_BLACK = 950,

	/// <summary>
	/// Predefined font weight : Ultra-black (950).
	/// </summary>
	DWRITE_FONT_WEIGHT_ULTRA_BLACK = 950
} DWRITE_FONT_WEIGHT;

/// <summary>
/// The font stretch enumeration describes relative change from the normal aspect ratio
/// as specified by a font designer for the glyphs in a font.
/// Values less than 1 or greater than 9 are considered to be invalid, and they are rejected by font API functions.
/// </summary>
typedef enum DWRITE_FONT_STRETCH {
	/// <summary>
	/// Predefined font stretch : Not known (0).
	/// </summary>
	DWRITE_FONT_STRETCH_UNDEFINED = 0,

	/// <summary>
	/// Predefined font stretch : Ultra-condensed (1).
	/// </summary>
	DWRITE_FONT_STRETCH_ULTRA_CONDENSED = 1,

	/// <summary>
	/// Predefined font stretch : Extra-condensed (2).
	/// </summary>
	DWRITE_FONT_STRETCH_EXTRA_CONDENSED = 2,

	/// <summary>
	/// Predefined font stretch : Condensed (3).
	/// </summary>
	DWRITE_FONT_STRETCH_CONDENSED = 3,

	/// <summary>
	/// Predefined font stretch : Semi-condensed (4).
	/// </summary>
	DWRITE_FONT_STRETCH_SEMI_CONDENSED = 4,

	/// <summary>
	/// Predefined font stretch : Normal (5).
	/// </summary>
	DWRITE_FONT_STRETCH_NORMAL = 5,

	/// <summary>
	/// Predefined font stretch : Medium (5).
	/// </summary>
	DWRITE_FONT_STRETCH_MEDIUM = 5,

	/// <summary>
	/// Predefined font stretch : Semi-expanded (6).
	/// </summary>
	DWRITE_FONT_STRETCH_SEMI_EXPANDED = 6,

	/// <summary>
	/// Predefined font stretch : Expanded (7).
	/// </summary>
	DWRITE_FONT_STRETCH_EXPANDED = 7,

	/// <summary>
	/// Predefined font stretch : Extra-expanded (8).
	/// </summary>
	DWRITE_FONT_STRETCH_EXTRA_EXPANDED = 8,

	/// <summary>
	/// Predefined font stretch : Ultra-expanded (9).
	/// </summary>
	DWRITE_FONT_STRETCH_ULTRA_EXPANDED = 9
} DWRITE_FONT_STRETCH;

/// <summary>
/// The font style enumeration describes the slope style of a font face, such as Normal, Italic or Oblique.
/// Values other than the ones defined in the enumeration are considered to be invalid, and they are rejected by font API functions.
/// </summary>
typedef enum DWRITE_FONT_STYLE {
	/// <summary>
	/// Font slope style : Normal.
	/// </summary>
	DWRITE_FONT_STYLE_NORMAL,

	/// <summary>
	/// Font slope style : Oblique.
	/// </summary>
	DWRITE_FONT_STYLE_OBLIQUE,

	/// <summary>
	/// Font slope style : Italic.
	/// </summary>
	DWRITE_FONT_STYLE_ITALIC

} DWRITE_FONT_STYLE;

/// <summary>
/// The informational string enumeration identifies a string in a font.
/// </summary>
typedef enum DWRITE_INFORMATIONAL_STRING_ID {
	/// <summary>
	/// Unspecified name ID.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_NONE,

	/// <summary>
	/// Copyright notice provided by the font.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE,

	/// <summary>
	/// String containing a version number.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_VERSION_STRINGS,

	/// <summary>
	/// Trademark information provided by the font.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_TRADEMARK,

	/// <summary>
	/// Name of the font manufacturer.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_MANUFACTURER,

	/// <summary>
	/// Name of the font designer.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_DESIGNER,

	/// <summary>
	/// URL of font designer (with protocol, e.g., http://, ftp://).
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_DESIGNER_URL,

	/// <summary>
	/// Description of the font. Can contain revision information, usage recommendations, history, features, etc.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_DESCRIPTION,

	/// <summary>
	/// URL of font vendor (with protocol, e.g., http://, ftp://). If a unique serial number is embedded in the URL, it can be used to register the font.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_FONT_VENDOR_URL,

	/// <summary>
	/// Description of how the font may be legally used, or different example scenarios for licensed use. This field should be written in plain language, not legalese.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION,

	/// <summary>
	/// URL where additional licensing information can be found.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_LICENSE_INFO_URL,

	/// <summary>
	/// GDI-compatible family name. Because GDI allows a maximum of four fonts per family, fonts in the same family may have different GDI-compatible family names
	/// (e.g., "Arial", "Arial Narrow", "Arial Black").
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES,

	/// <summary>
	/// GDI-compatible subfamily name.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES,

	/// <summary>
	/// Typographic family name preferred by the designer. This enables font designers to group more than four fonts in a single family without losing compatibility with
	/// GDI. This name is typically only present if it differs from the GDI-compatible family name.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_FAMILY_NAMES,

	/// <summary>
	/// Typographic subfamily name preferred by the designer. This name is typically only present if it differs from the GDI-compatible subfamily name.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_SUBFAMILY_NAMES,

	/// <summary>
	/// Sample text. This can be the font name or any other text that the designer thinks is the best example to display the font in.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT,

	/// <summary>
	/// The full name of the font, e.g. "Arial Bold", from name id 4 in the name table.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_FULL_NAME,

	/// <summary>
	/// The postscript name of the font, e.g. "GillSans-Bold" from name id 6 in the name table.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME,

	/// <summary>
	/// The postscript CID findfont name, from name id 20 in the name table.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_CID_NAME,

	/// <summary>
	/// Family name for the weight-stretch-style model.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_WEIGHT_STRETCH_STYLE_FAMILY_NAME,

	/// <summary>
	/// Script/language tag to identify the scripts or languages that the font was
	/// primarily designed to support. See DWRITE_FONT_PROPERTY_ID_DESIGN_SCRIPT_LANGUAGE_TAG
	/// for a longer description.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_DESIGN_SCRIPT_LANGUAGE_TAG,

	/// <summary>
	/// Script/language tag to identify the scripts or languages that the font declares
	/// it is able to support.
	/// </summary>
	DWRITE_INFORMATIONAL_STRING_SUPPORTED_SCRIPT_LANGUAGE_TAG,

	// Obsolete aliases kept to avoid breaking existing code.
	DWRITE_INFORMATIONAL_STRING_PREFERRED_FAMILY_NAMES = DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_FAMILY_NAMES,
	DWRITE_INFORMATIONAL_STRING_PREFERRED_SUBFAMILY_NAMES = DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_SUBFAMILY_NAMES,
	DWRITE_INFORMATIONAL_STRING_WWS_FAMILY_NAME = DWRITE_INFORMATIONAL_STRING_WEIGHT_STRETCH_STYLE_FAMILY_NAME,
} DWRITE_INFORMATIONAL_STRING_ID;


/// <summary>
/// The DWRITE_FONT_METRICS structure specifies the metrics of a font face that
/// are applicable to all glyphs within the font face.
/// </summary>
typedef struct DWRITE_FONT_METRICS {
	/// <summary>
	/// The number of font design units per em unit.
	/// Font files use their own coordinate system of font design units.
	/// A font design unit is the smallest measurable unit in the em square,
	/// an imaginary square that is used to size and align glyphs.
	/// The concept of em square is used as a reference scale factor when defining font size and device transformation semantics.
	/// The size of one em square is also commonly used to compute the paragraph indentation value.
	/// </summary>
	UINT16 designUnitsPerEm;

	/// <summary>
	/// Ascent value of the font face in font design units.
	/// Ascent is the distance from the top of font character alignment box to English baseline.
	/// </summary>
	UINT16 ascent;

	/// <summary>
	/// Descent value of the font face in font design units.
	/// Descent is the distance from the bottom of font character alignment box to English baseline.
	/// </summary>
	UINT16 descent;

	/// <summary>
	/// Line gap in font design units.
	/// Recommended additional white space to add between lines to improve legibility. The recommended line spacing
	/// (baseline-to-baseline distance) is thus the sum of ascent, descent, and lineGap. The line gap is usually
	/// positive or zero but can be negative, in which case the recommended line spacing is less than the height
	/// of the character alignment box.
	/// </summary>
	INT16 lineGap;

	/// <summary>
	/// Cap height value of the font face in font design units.
	/// Cap height is the distance from English baseline to the top of a typical English capital.
	/// Capital "H" is often used as a reference character for the purpose of calculating the cap height value.
	/// </summary>
	UINT16 capHeight;

	/// <summary>
	/// x-height value of the font face in font design units.
	/// x-height is the distance from English baseline to the top of lowercase letter "x", or a similar lowercase character.
	/// </summary>
	UINT16 xHeight;

	/// <summary>
	/// The underline position value of the font face in font design units.
	/// Underline position is the position of underline relative to the English baseline.
	/// The value is usually made negative in order to place the underline below the baseline.
	/// </summary>
	INT16 underlinePosition;

	/// <summary>
	/// The suggested underline thickness value of the font face in font design units.
	/// </summary>
	UINT16 underlineThickness;

	/// <summary>
	/// The strikethrough position value of the font face in font design units.
	/// Strikethrough position is the position of strikethrough relative to the English baseline.
	/// The value is usually made positive in order to place the strikethrough above the baseline.
	/// </summary>
	INT16 strikethroughPosition;

	/// <summary>
	/// The suggested strikethrough thickness value of the font face in font design units.
	/// </summary>
	UINT16 strikethroughThickness;
} DWRITE_FONT_METRICS;

/// <summary>
/// The DWRITE_GLYPH_METRICS structure specifies the metrics of an individual glyph.
/// The units depend on how the metrics are obtained.
/// </summary>
typedef struct DWRITE_GLYPH_METRICS {
	/// <summary>
	/// Specifies the X offset from the glyph origin to the left edge of the black box.
	/// The glyph origin is the current horizontal writing position.
	/// A negative value means the black box extends to the left of the origin (often true for lowercase italic 'f').
	/// </summary>
	INT32 leftSideBearing;

	/// <summary>
	/// Specifies the X offset from the origin of the current glyph to the origin of the next glyph when writing horizontally.
	/// </summary>
	UINT32 advanceWidth;

	/// <summary>
	/// Specifies the X offset from the right edge of the black box to the origin of the next glyph when writing horizontally.
	/// The value is negative when the right edge of the black box overhangs the layout box.
	/// </summary>
	INT32 rightSideBearing;

	/// <summary>
	/// Specifies the vertical offset from the vertical origin to the top of the black box.
	/// Thus, a positive value adds whitespace whereas a negative value means the glyph overhangs the top of the layout box.
	/// </summary>
	INT32 topSideBearing;

	/// <summary>
	/// Specifies the Y offset from the vertical origin of the current glyph to the vertical origin of the next glyph when writing vertically.
	/// (Note that the term "origin" by itself denotes the horizontal origin. The vertical origin is different.
	/// Its Y coordinate is specified by verticalOriginY value,
	/// and its X coordinate is half the advanceWidth to the right of the horizontal origin).
	/// </summary>
	UINT32 advanceHeight;

	/// <summary>
	/// Specifies the vertical distance from the black box's bottom edge to the advance height.
	/// Positive when the bottom edge of the black box is within the layout box.
	/// Negative when the bottom edge of black box overhangs the layout box.
	/// </summary>
	INT32 bottomSideBearing;

	/// <summary>
	/// Specifies the Y coordinate of a glyph's vertical origin, in the font's design coordinate system.
	/// The y coordinate of a glyph's vertical origin is the sum of the glyph's top side bearing
	/// and the top (i.e. yMax) of the glyph's bounding box.
	/// </summary>
	INT32 verticalOriginY;
} DWRITE_GLYPH_METRICS;

/// <summary>
/// Optional adjustment to a glyph's position. A glyph offset changes the position of a glyph without affecting
/// the pen position. Offsets are in logical, pre-transform units.
/// </summary>
typedef struct DWRITE_GLYPH_OFFSET {
	/// <summary>
	/// Offset in the advance direction of the run. A positive advance offset moves the glyph to the right
	/// (in pre-transform coordinates) if the run is left-to-right or to the left if the run is right-to-left.
	/// </summary>
	FLOAT advanceOffset;

	/// <summary>
	/// Offset in the ascent direction, i.e., the direction ascenders point. A positive ascender offset moves
	/// the glyph up (in pre-transform coordinates).
	/// </summary>
	FLOAT ascenderOffset;
} DWRITE_GLYPH_OFFSET;

/// <summary>
/// Specifies the type of DirectWrite factory object.
/// DirectWrite factory contains internal state such as font loader registration and cached font data.
/// In most cases it is recommended to use the shared factory object, because it allows multiple components
/// that use DirectWrite to share internal DirectWrite state and reduce memory usage.
/// However, there are cases when it is desirable to reduce the impact of a component,
/// such as a plug-in from an untrusted source, on the rest of the process by sandboxing and isolating it
/// from the rest of the process components. In such cases, it is recommended to use an isolated factory for the sandboxed
/// component.
/// </summary>
typedef enum DWRITE_FACTORY_TYPE {
	/// <summary>
	/// Shared factory allow for re-use of cached font data across multiple in process components.
	/// Such factories also take advantage of cross process font caching components for better performance.
	/// </summary>
	DWRITE_FACTORY_TYPE_SHARED,

	/// <summary>
	/// Objects created from the isolated factory do not interact with internal DirectWrite state from other components.
	/// </summary>
	DWRITE_FACTORY_TYPE_ISOLATED
} DWRITE_FACTORY_TYPE;

/// <summary>
/// Creates an OpenType tag as a 32bit integer such that
/// the first character in the tag is the lowest byte,
/// (least significant on little endian architectures)
/// which can be used to compare with tags in the font file.
/// This macro is compatible with DWRITE_FONT_FEATURE_TAG.
///
/// Example: DWRITE_MAKE_OPENTYPE_TAG('c','c','m','p')
/// Dword:   0x706D6363
/// </summary>
#define DWRITE_MAKE_OPENTYPE_TAG(a,b,c,d) ( \
    ((UINT32)((UINT8)(d)) << 24) | \
    ((UINT32)((UINT8)(c)) << 16) | \
    ((UINT32)((UINT8)(b)) << 8)  | \
     (UINT32)((UINT8)(a)))

/// <summary>
/// Creates an OpenType tag for glyph positioning and substitution font features.
/// </summary>
#define DWRITE_MAKE_FONT_FEATURE_TAG(a,b,c,d) ((DWRITE_FONT_FEATURE_TAG)(DWRITE_MAKE_OPENTYPE_TAG(a,b,c,d)))


struct IDWriteFontFileLoaderVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFontFileLoader* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFontFileLoader* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFontFileLoader* This);

	STDMETHOD(CreateStreamFromKey)(
		IDWriteFontFileLoader* This,
		_In_reads_bytes_(fontFileReferenceKeySize) void const* fontFileReferenceKey,
		UINT32 fontFileReferenceKeySize,
		_COM_Outptr_ IDWriteFontFileStream** fontFileStream
		) PURE;
};

interface IDWriteFontFileLoader {
	struct IDWriteFontFileLoaderVtbl* lpVtbl;
};

#define IDWriteFontFileLoader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )

#define IDWriteFontFileLoader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) )

#define IDWriteFontFileLoader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) )

#define IDWriteFontFileLoader_CreateStreamFromKey(This,fontFileReferenceKey,fontFileReferenceKeySize,fontFileStream) \
	((This)->lpVtbl->CreateStreamFromKey(This,fontFileReferenceKey,fontFileReferenceKeySize,fontFileStream))


struct IDWriteLocalFontFileLoaderVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteLocalFontFileLoader* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteLocalFontFileLoader* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteLocalFontFileLoader* This);

	STDMETHOD(CreateStreamFromKey)(
		IDWriteLocalFontFileLoader* This,
		_In_reads_bytes_(fontFileReferenceKeySize) void const* fontFileReferenceKey,
		UINT32 fontFileReferenceKeySize,
		_COM_Outptr_ IDWriteFontFileStream** fontFileStream
		) PURE;

	STDMETHOD(GetFilePathLengthFromKey)(
		IDWriteLocalFontFileLoader* This,
		_In_reads_bytes_(fontFileReferenceKeySize) void const* fontFileReferenceKey,
		UINT32 fontFileReferenceKeySize,
		_Out_ UINT32* filePathLength
		) PURE;

	STDMETHOD(GetFilePathFromKey)(
		IDWriteLocalFontFileLoader* This,
		_In_reads_bytes_(fontFileReferenceKeySize) void const* fontFileReferenceKey,
		UINT32 fontFileReferenceKeySize,
		_Out_writes_z_(filePathSize) WCHAR* filePath,
		UINT32 filePathSize
		) PURE;

	STDMETHOD(GetLastWriteTimeFromKey)(
		IDWriteLocalFontFileLoader* This,
		_In_reads_bytes_(fontFileReferenceKeySize) void const* fontFileReferenceKey,
		UINT32 fontFileReferenceKeySize,
		_Out_ FILETIME* lastWriteTime
		) PURE;
};

interface IDWriteLocalFontFileLoader {
	struct IDWriteLocalFontFileLoaderVtbl* lpVtbl;
};

#define IDWriteLocalFontFileLoader_QueryInterface(This,riid,ppvObject)	\
	( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )

#define IDWriteLocalFontFileLoader_AddRef(This)	\
	( (This)->lpVtbl -> AddRef(This) )

#define IDWriteLocalFontFileLoader_Release(This)	\
	( (This)->lpVtbl -> Release(This) )

#define IDWriteLocalFontFileLoader_CreateStreamFromKey(This,fontFileReferenceKey,fontFileReferenceKeySize,fontFileStream) \
	((This)->lpVtbl->CreateStreamFromKey(This,fontFileReferenceKey,fontFileReferenceKeySize,fontFileStream))

#define IDWriteLocalFontFileLoader_GetFilePathLengthFromKey(This,fontFileReferenceKey,fontFileReferenceKeySize,filePathLength) \
	((This)->lpVtbl->GetFilePathLengthFromKey(This,fontFileReferenceKey,fontFileReferenceKeySize,filePathLength))

#define IDWriteLocalFontFileLoader_GetFilePathFromKey(This,fontFileReferenceKey,fontFileReferenceKeySize,filePath,filePathSize) \
	((This)->lpVtbl->GetFilePathFromKey(This,fontFileReferenceKey,fontFileReferenceKeySize,filePath,filePathSize))

#define IDWriteLocalFontFileLoader_GetLastWriteTimeFromKey(This,fontFileReferenceKey,fontFileReferenceKeySize,lastWriteTime) \
	((This)->lpVtbl->GetLastWriteTimeFromKey(This,fontFileReferenceKey,fontFileReferenceKeySize,lastWriteTime))


struct IDWriteFontFileStreamVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFontFileStream* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFontFileStream* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFontFileStream* This);

	STDMETHOD(ReadFileFragment)(
		IDWriteFontFileStream* This,
		_Outptr_result_bytebuffer_(fragmentSize) void const** fragmentStart,
		UINT64 fileOffset,
		UINT64 fragmentSize,
		_Out_ void** fragmentContext
		) PURE;

	STDMETHOD_(void, ReleaseFileFragment)(
		IDWriteFontFileStream* This,
		void* fragmentContext
		) PURE;

	STDMETHOD(GetFileSize)(
		IDWriteFontFileStream* This,
		_Out_ UINT64* fileSize
		) PURE;

	STDMETHOD(GetLastWriteTime)(
		IDWriteFontFileStream* This,
		_Out_ UINT64* lastWriteTime
		) PURE;
};

interface IDWriteFontFileStream {
	struct IDWriteFontFileStreamVtbl* lpVtbl;
};

#define IDWriteFontFileStream_QueryInterface(This,riid,ppvObject)	\
	( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )

#define IDWriteFontFileStream_AddRef(This)	\
	( (This)->lpVtbl -> AddRef(This) )

#define IDWriteFontFileStream_Release(This)	\
	( (This)->lpVtbl -> Release(This) )

#define IDWriteFontFileStream_ReadFileFragment(This,fragmentStart,fileOffset,fragmentSize,fragmentContext) \
	((This)->lpVtbl->ReadFileFragment(This,fragmentStart,fileOffset,fragmentSize,fragmentContext))

#define IDWriteFontFileStream_ReleaseFileFragment(This,fragmentContext) \
	((This)->lpVtbl->ReleaseFileFragment(This,fragmentContext))

#define IDWriteFontFileStream_GetFileSize(This,fileSize) \
	((This)->lpVtbl->GetFileSize(This,fileSize))

#define IDWriteFontFileStream_GetLastWriteTime(This,lastWriteTime) \
	((This)->lpVtbl->GetLastWriteTime(This,lastWriteTime))


struct IDWriteFontFileVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFontFile* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFontFile* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFontFile* This);

	STDMETHOD(GetReferenceKey)(
		IDWriteFontFile* This,
		_Outptr_result_bytebuffer_(*fontFileReferenceKeySize) void const** fontFileReferenceKey,
		_Out_ UINT32* fontFileReferenceKeySize
		) PURE;

	STDMETHOD(GetLoader)(
		IDWriteFontFile* This,
		_COM_Outptr_ IDWriteFontFileLoader** fontFileLoader
		) PURE;

	STDMETHOD(Analyze)(
		IDWriteFontFile* This,
		_Out_ BOOL* isSupportedFontType,
		_Out_ DWRITE_FONT_FILE_TYPE* fontFileType,
		_Out_opt_ DWRITE_FONT_FACE_TYPE* fontFaceType,
		_Out_ UINT32* numberOfFaces
		) PURE;
};

interface IDWriteFontFile {
	struct IDWriteFontFileVtbl* lpVtbl;
};

#define IDWriteFontFile_QueryInterface(This,riid,ppvObject)	\
	( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )

#define IDWriteFontFile_AddRef(This)	\
	( (This)->lpVtbl -> AddRef(This) )

#define IDWriteFontFile_Release(This)	\
	( (This)->lpVtbl -> Release(This) )

#define IDWriteFontFile_GetReferenceKey(This,fontFileReferenceKey,fontFileReferenceKeySize) \
	((This)->lpVtbl->GetReferenceKey(This,fontFileReferenceKey,fontFileReferenceKeySize))

#define IDWriteFontFile_GetLoader(This,fontFileLoader) \
	((This)->lpVtbl->GetLoader(This,fontFileLoader))

#define IDWriteFontFile_Analyze(This,isSupportedFontType,fontFileType,fontFaceType,numberOfFaces) \
	((This)->lpVtbl->Analyze(This,isSupportedFontType,fontFileType,fontFaceType,numberOfFaces))


#ifndef DWRITE_PIXEL_GEOMETRY_DEFINED
typedef enum DWRITE_PIXEL_GEOMETRY {
	/// <summary>
	/// The red, green, and blue color components of each pixel are assumed to occupy the same point.
	/// </summary>
	DWRITE_PIXEL_GEOMETRY_FLAT,

	/// <summary>
	/// Each pixel comprises three vertical stripes, with red on the left, green in the center, and
	/// blue on the right. This is the most common pixel geometry for LCD monitors.
	/// </summary>
	DWRITE_PIXEL_GEOMETRY_RGB,

	/// <summary>
	/// Each pixel comprises three vertical stripes, with blue on the left, green in the center, and
	/// red on the right.
	/// </summary>
	DWRITE_PIXEL_GEOMETRY_BGR
} DWRITE_PIXEL_GEOMETRY;
#define DWRITE_PIXEL_GEOMETRY_DEFINED
#endif

/// <summary>
/// Represents a method of rendering glyphs.
/// </summary>
typedef enum DWRITE_RENDERING_MODE {
	/// <summary>
	/// Specifies that the rendering mode is determined automatically based on the font and size.
	/// </summary>
	DWRITE_RENDERING_MODE_DEFAULT,

	/// <summary>
	/// Specifies that no antialiasing is performed. Each pixel is either set to the foreground
	/// color of the text or retains the color of the background.
	/// </summary>
	DWRITE_RENDERING_MODE_ALIASED,

	/// <summary>
	/// Specifies that antialiasing is performed in the horizontal direction and the appearance
	/// of glyphs is layout-compatible with GDI using CLEARTYPE_QUALITY. Use DWRITE_MEASURING_MODE_GDI_CLASSIC
	/// to get glyph advances. The antialiasing may be either ClearType or grayscale depending on
	/// the text antialiasing mode.
	/// </summary>
	DWRITE_RENDERING_MODE_GDI_CLASSIC,

	/// <summary>
	/// Specifies that antialiasing is performed in the horizontal direction and the appearance
	/// of glyphs is layout-compatible with GDI using CLEARTYPE_NATURAL_QUALITY. Glyph advances
	/// are close to the font design advances, but are still rounded to whole pixels. Use
	/// DWRITE_MEASURING_MODE_GDI_NATURAL to get glyph advances. The antialiasing may be either
	/// ClearType or grayscale depending on the text antialiasing mode.
	/// </summary>
	DWRITE_RENDERING_MODE_GDI_NATURAL,

	/// <summary>
	/// Specifies that antialiasing is performed in the horizontal direction. This rendering
	/// mode allows glyphs to be positioned with subpixel precision and is therefore suitable
	/// for natural (i.e., resolution-independent) layout. The antialiasing may be either
	/// ClearType or grayscale depending on the text antialiasing mode.
	/// </summary>
	DWRITE_RENDERING_MODE_NATURAL,

	/// <summary>
	/// Similar to natural mode except that antialiasing is performed in both the horizontal
	/// and vertical directions. This is typically used at larger sizes to make curves and
	/// diagonal lines look smoother. The antialiasing may be either ClearType or grayscale
	/// depending on the text antialiasing mode.
	/// </summary>
	DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC,

	/// <summary>
	/// Specifies that rendering should bypass the rasterizer and use the outlines directly.
	/// This is typically used at very large sizes.
	/// </summary>
	DWRITE_RENDERING_MODE_OUTLINE,

	// The following names are obsolete, but are kept as aliases to avoid breaking existing code.
	// Each of these rendering modes may result in either ClearType or grayscale antialiasing
	// depending on the DWRITE_TEXT_ANTIALIASING_MODE.
	DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC = DWRITE_RENDERING_MODE_GDI_CLASSIC,
	DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL = DWRITE_RENDERING_MODE_GDI_NATURAL,
	DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL = DWRITE_RENDERING_MODE_NATURAL,
	DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC = DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC
} DWRITE_RENDERING_MODE;

/// <summary>
/// The DWRITE_MATRIX structure specifies the graphics transform to be applied
/// to rendered glyphs.
/// </summary>
typedef struct DWRITE_MATRIX {
	/// <summary>
	/// Horizontal scaling / cosine of rotation
	/// </summary>
	FLOAT m11;

	/// <summary>
	/// Vertical shear / sine of rotation
	/// </summary>
	FLOAT m12;

	/// <summary>
	/// Horizontal shear / negative sine of rotation
	/// </summary>
	FLOAT m21;

	/// <summary>
	/// Vertical scaling / cosine of rotation
	/// </summary>
	FLOAT m22;

	/// <summary>
	/// Horizontal shift (always orthogonal regardless of rotation)
	/// </summary>
	FLOAT dx;

	/// <summary>
	/// Vertical shift (always orthogonal regardless of rotation)
	/// </summary>
	FLOAT dy;
} DWRITE_MATRIX;


struct IDWriteRenderingParamsVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteRenderingParams* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteRenderingParams* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteRenderingParams* This);

	STDMETHOD_(FLOAT, GetGamma)(
		IDWriteRenderingParams* This) PURE;

	STDMETHOD_(FLOAT, GetEnhancedContrast)(
		IDWriteRenderingParams* This) PURE;

	STDMETHOD_(FLOAT, GetClearTypeLevel)(
		IDWriteRenderingParams* This) PURE;

	STDMETHOD_(DWRITE_PIXEL_GEOMETRY, GetPixelGeometry)(
		IDWriteRenderingParams* This) PURE;

	STDMETHOD_(DWRITE_RENDERING_MODE, GetRenderingMode)(
		IDWriteRenderingParams* This) PURE;
};

interface IDWriteRenderingParams {
	struct IDWriteRenderingParamsVtbl* lpVtbl;
};

#define IDWriteRenderingParams_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteRenderingParams_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteRenderingParams_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteRenderingParams_GetGamma(This) \
	((This)->lpVtbl->GetGamma(This))

#define IDWriteRenderingParams_GetEnhancedContrast(This) \
	((This)->lpVtbl->GetEnhancedContrast(This))

#define IDWriteRenderingParams_GetClearTypeLevel(This) \
	((This)->lpVtbl->GetClearTypeLevel(This))

#define IDWriteRenderingParams_GetPixelGeometry(This) \
	((This)->lpVtbl->GetPixelGeometry(This))

#define IDWriteRenderingParams_GetRenderingMode(This) \
	((This)->lpVtbl->GetRenderingMode(This))


// Forward declarations of D2D types
typedef interface ID2D1SimplifiedGeometrySink ID2D1SimplifiedGeometrySink;

typedef ID2D1SimplifiedGeometrySink IDWriteGeometrySink;


struct IDWriteFontFaceVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFontFace* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFontFace* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFontFace* This);

	STDMETHOD_(DWRITE_FONT_FACE_TYPE, GetType)() PURE;

	STDMETHOD(GetFiles)(
		IDWriteFontFace* This,
		_Inout_ UINT32* numberOfFiles,
		_Out_writes_opt_(*numberOfFiles) IDWriteFontFile** fontFiles
		) PURE;

	STDMETHOD_(UINT32, GetIndex)(
		IDWriteFontFace* This) PURE;

	STDMETHOD_(DWRITE_FONT_SIMULATIONS, GetSimulations)(
		IDWriteFontFace* This) PURE;

	STDMETHOD_(BOOL, IsSymbolFont)(
		IDWriteFontFace* This) PURE;

	STDMETHOD_(void, GetMetrics)(
		IDWriteFontFace* This,
		_Out_ DWRITE_FONT_METRICS* fontFaceMetrics
		) PURE;

	STDMETHOD_(UINT16, GetGlyphCount)(
		IDWriteFontFace* This) PURE;

	STDMETHOD(GetDesignGlyphMetrics)(
		IDWriteFontFace* This,
		_In_reads_(glyphCount) UINT16 const* glyphIndices,
		UINT32 glyphCount,
		_Out_writes_(glyphCount) DWRITE_GLYPH_METRICS* glyphMetrics,
		BOOL isSideways
		) PURE;

	STDMETHOD(GetGlyphIndices)(
		IDWriteFontFace* This,
		_In_reads_(codePointCount) UINT32 const* codePoints,
		UINT32 codePointCount,
		_Out_writes_(codePointCount) UINT16* glyphIndices
		) PURE;

	STDMETHOD(TryGetFontTable)(
		IDWriteFontFace* This,
		_In_ UINT32 openTypeTableTag,
		_Outptr_result_bytebuffer_(*tableSize) const void** tableData,
		_Out_ UINT32* tableSize,
		_Out_ void** tableContext,
		_Out_ BOOL* exists
		) PURE;

	STDMETHOD_(void, ReleaseFontTable)(
		IDWriteFontFace* This,
		_In_ void* tableContext
		) PURE;

	STDMETHOD(GetGlyphRunOutline)(
		IDWriteFontFace* This,
		FLOAT emSize,
		_In_reads_(glyphCount) UINT16 const* glyphIndices,
		_In_reads_opt_(glyphCount) FLOAT const* glyphAdvances,
		_In_reads_opt_(glyphCount) DWRITE_GLYPH_OFFSET const* glyphOffsets,
		UINT32 glyphCount,
		BOOL isSideways,
		BOOL isRightToLeft,
		_In_ IDWriteGeometrySink* geometrySink
		) PURE;

	STDMETHOD(GetRecommendedRenderingMode)(
		IDWriteFontFace* This,
		FLOAT emSize,
		FLOAT pixelsPerDip,
		DWRITE_MEASURING_MODE measuringMode,
		IDWriteRenderingParams* renderingParams,
		_Out_ DWRITE_RENDERING_MODE* renderingMode
		) PURE;

	STDMETHOD(GetGdiCompatibleMetrics)(
		IDWriteFontFace* This,
		FLOAT emSize,
		FLOAT pixelsPerDip,
		_In_opt_ DWRITE_MATRIX const* transform,
		_Out_ DWRITE_FONT_METRICS* fontFaceMetrics
		) PURE;

	STDMETHOD(GetGdiCompatibleGlyphMetrics)(
		IDWriteFontFace* This,
		FLOAT emSize,
		FLOAT pixelsPerDip,
		_In_opt_ DWRITE_MATRIX const* transform,
		BOOL useGdiNatural,
		_In_reads_(glyphCount) UINT16 const* glyphIndices,
		UINT32 glyphCount,
		_Out_writes_(glyphCount) DWRITE_GLYPH_METRICS* glyphMetrics,
		BOOL isSideways
		) PURE;
};

interface IDWriteFontFace {
	struct IDWriteFontFaceVtbl* lpVtbl;
};

#define IDWriteFontFace_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteFontFace_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteFontFace_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteFontFace_GetType() \
	((This)->lpVtbl->GetType(This))

#define IDWriteFontFace_GetFiles() \
	((This)->lpVtbl->GetFiles(This))

#define IDWriteFontFace_GetIndex() \
	((This)->lpVtbl->GetIndex(This))

#define IDWriteFontFace_GetSimulations() \
	((This)->lpVtbl->GetSimulations(This))

#define IDWriteFontFace_IsSymbolFont() \
	((This)->lpVtbl->IsSymbolFont(This))

#define IDWriteFontFace_GetMetrics() \
	((This)->lpVtbl->GetMetrics(This))

#define IDWriteFontFace_GetGlyphCount() \
	((This)->lpVtbl->GetGlyphCount(This))

#define IDWriteFontFace_GetDesignGlyphMetrics() \
	((This)->lpVtbl->GetDesignGlyphMetrics(This))

#define IDWriteFontFace_GetGlyphIndices() \
	((This)->lpVtbl->GetGlyphIndices(This))

#define IDWriteFontFace_TryGetFontTable() \
	((This)->lpVtbl->TryGetFontTable(This))

#define IDWriteFontFace_ReleaseFontTable() \
	((This)->lpVtbl->ReleaseFontTable(This))

#define IDWriteFontFace_GetGlyphRunOutline() \
	((This)->lpVtbl->GetGlyphRunOutline(This))

#define IDWriteFontFace_GetRecommendedRenderingMode() \
	((This)->lpVtbl->GetRecommendedRenderingMode(This))

#define IDWriteFontFace_GetGdiCompatibleMetrics() \
	((This)->lpVtbl->GetGdiCompatibleMetrics(This))

#define IDWriteFontFace_GetGdiCompatibleGlyphMetrics() \
	((This)->lpVtbl->GetGdiCompatibleGlyphMetrics(This))


struct IDWriteFontCollectionLoaderVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFontCollectionLoader* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFontCollectionLoader* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFontCollectionLoader* This);

	STDMETHOD(CreateEnumeratorFromKey)(
		IDWriteFontCollectionLoader* This,
		_In_ IDWriteFactory* factory,
		_In_reads_bytes_(collectionKeySize) void const* collectionKey,
		UINT32 collectionKeySize,
		_COM_Outptr_ IDWriteFontFileEnumerator** fontFileEnumerator
		) PURE;
};

interface IDWriteFontCollectionLoader {
	struct IDWriteFontCollectionLoaderVtbl* lpVtbl;
};

#define IDWriteFontCollectionLoader_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteFontCollectionLoader_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteFontCollectionLoader_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteFontCollectionLoader_CreateEnumeratorFromKey(This,factory,collectionKey,collectionKeySize,fontFileEnumerator) \
	((This)->lpVtbl->CreateEnumeratorFromKey(This,factory,collectionKey,collectionKeySize,fontFileEnumerator))


struct IDWriteFontFileEnumeratorVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFontFileEnumerator* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFontFileEnumerator* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFontFileEnumerator* This);

	STDMETHOD(MoveNext)(
		IDWriteFontFileEnumerator* This,
		_Out_ BOOL* hasCurrentFile
		) PURE;

	STDMETHOD(GetCurrentFontFile)(
		IDWriteFontFileEnumerator* This,
		_COM_Outptr_ IDWriteFontFile** fontFile
		) PURE;
};

interface IDWriteFontFileEnumerator {
	struct IDWriteFontFileEnumeratorVtbl* lpVtbl;
};

#define IDWriteFontFileEnumerator_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteFontFileEnumerator_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteFontFileEnumerator_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteFontFileEnumerator_MoveNext(This,hasCurrentFile) \
	((This)->lpVtbl->MoveNext(This,hasCurrentFile))


struct IDWriteLocalizedStringsVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteLocalizedStrings* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteLocalizedStrings* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteLocalizedStrings* This);

	STDMETHOD_(UINT32, GetCount)(
		IDWriteLocalizedStrings* This) PURE;

	STDMETHOD(FindLocaleName)(
		IDWriteLocalizedStrings* This,
		_In_z_ WCHAR const* localeName,
		_Out_ UINT32* index,
		_Out_ BOOL* exists
		) PURE;

	STDMETHOD(GetLocaleNameLength)(
		IDWriteLocalizedStrings* This,
		UINT32 index,
		_Out_ UINT32* length
		) PURE;

	STDMETHOD(GetLocaleName)(
		IDWriteLocalizedStrings* This,
		UINT32 index,
		_Out_writes_z_(size) WCHAR* localeName,
		UINT32 size
		) PURE;

	STDMETHOD(GetStringLength)(
		IDWriteLocalizedStrings* This,
		UINT32 index,
		_Out_ UINT32* length
		) PURE;

	STDMETHOD(GetString)(
		IDWriteLocalizedStrings* This,
		UINT32 index,
		_Out_writes_z_(size) WCHAR* stringBuffer,
		UINT32 size
		) PURE;
};

interface IDWriteLocalizedStrings {
	struct IDWriteLocalizedStringsVtbl* lpVtbl;
};

#define IDWriteLocalizedStrings_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteLocalizedStrings_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteLocalizedStrings_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteLocalizedStrings_GetCount(This) \
	((This)->lpVtbl->GetCount(This))

#define IDWriteLocalizedStrings_FindLocaleName(This,localeName,index,exists) \
	((This)->lpVtbl->FindLocaleName(This,localeName,index,exists))

#define IDWriteLocalizedStrings_GetLocaleNameLength(This,index,length) \
	((This)->lpVtbl->GetLocaleNameLength(This,index,length))

#define IDWriteLocalizedStrings_GetLocaleName(This,index,localeName,size) \
	((This)->lpVtbl->GetLocaleName(This,index,localeName,size))

#define IDWriteLocalizedStrings_GetStringLength(This,index,length) \
	((This)->lpVtbl->GetStringLength(This,index,length))

#define IDWriteLocalizedStrings_GetString(This,index,stringBuffer,size) \
	((This)->lpVtbl->GetString(This,index,stringBuffer,size))


struct IDWriteFontCollectionVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFontCollection* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFontCollection* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFontCollection* This);

	STDMETHOD_(UINT32, GetFontFamilyCount)(
		IDWriteFontCollection* This) PURE;

	STDMETHOD(GetFontFamily)(
		IDWriteFontCollection* This,
		UINT32 index,
		_COM_Outptr_ IDWriteFontFamily** fontFamily
		) PURE;

	STDMETHOD(FindFamilyName)(
		IDWriteFontCollection* This,
		_In_z_ WCHAR const* familyName,
		_Out_ UINT32* index,
		_Out_ BOOL* exists
		) PURE;

	STDMETHOD(GetFontFromFontFace)(
		IDWriteFontCollection* This,
		_In_ IDWriteFontFace* fontFace,
		_COM_Outptr_ IDWriteFont** font
		) PURE;
};

interface IDWriteFontCollection {
	struct IDWriteFontCollectionVtbl* lpVtbl;
};

#define IDWriteFontCollection_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteFontCollection_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteFontCollection_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteFontCollection_GetFontFamilyCount(This) \
	((This)->lpVtbl->GetFontFamilyCount(This))

#define IDWriteFontCollection_GetFontFamily(This,index,fontFamily) \
	((This)->lpVtbl->GetFontFamily(This,index,fontFamily))

#define IDWriteFontCollection_FindFamilyName(This,familyName,index,exists) \
	((This)->lpVtbl->FindFamilyName(This,familyName,index,exists))

#define IDWriteFontCollection_GetFontFromFontFace(This,fontFace,font) \
	((This)->lpVtbl->GetFontFromFontFace(This,fontFace,font))


struct IDWriteFontListVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFontList* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFontList* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFontList* This);

	STDMETHOD(GetFontCollection)(
		IDWriteFontList* This,
		_COM_Outptr_ IDWriteFontCollection** fontCollection
		) PURE;

	STDMETHOD_(UINT32, GetFontCount)(
		IDWriteFontList* This) PURE;

	STDMETHOD(GetFont)(
		IDWriteFontList* This,
		UINT32 index,
		_COM_Outptr_ IDWriteFont** font
		) PURE;
};

interface IDWriteFontList {
	struct IDWriteFontListVtbl* lpVtbl;
};

#define IDWriteFontList_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteFontList_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteFontList_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteFontList_GetFontCollection(This,fontCollection) \
	((This)->lpVtbl->GetFontCollection(This,fontCollection))

#define IDWriteFontList_GetFontCount(This) \
	((This)->lpVtbl->GetFontCount(This))

#define IDWriteFontList_GetFont(This,index,font) \
	((This)->lpVtbl->GetFont(This,index,font))


struct IDWriteFontFamilyVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFontFamily* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFontFamily* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFontFamily* This);

	STDMETHOD(GetFontCollection)(
		IDWriteFontFamily* This,
		_COM_Outptr_ IDWriteFontCollection** fontCollection
		) PURE;

	STDMETHOD_(UINT32, GetFontCount)(
		IDWriteFontFamily* This) PURE;

	STDMETHOD(GetFont)(
		IDWriteFontFamily* This,
		UINT32 index,
		_COM_Outptr_ IDWriteFont** font
		) PURE;

	STDMETHOD(GetFamilyNames)(
		IDWriteFontFamily* This,
		_COM_Outptr_ IDWriteLocalizedStrings** names
		) PURE;

	STDMETHOD(GetFirstMatchingFont)(
		IDWriteFontFamily* This,
		DWRITE_FONT_WEIGHT  weight,
		DWRITE_FONT_STRETCH stretch,
		DWRITE_FONT_STYLE   style,
		_COM_Outptr_ IDWriteFont** matchingFont
		) PURE;

	STDMETHOD(GetMatchingFonts)(
		IDWriteFontFamily* This,
		DWRITE_FONT_WEIGHT      weight,
		DWRITE_FONT_STRETCH     stretch,
		DWRITE_FONT_STYLE       style,
		_COM_Outptr_ IDWriteFontList** matchingFonts
		) PURE;
};

interface IDWriteFontFamily {
	struct IDWriteFontFamilyVtbl* lpVtbl;
};

#define IDWriteFontFamily_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteFontFamily_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteFontFamily_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteFontFamily_GetFontCollection(This,fontCollection) \
	((This)->lpVtbl->GetFontCollection(This,fontCollection))

#define IDWriteFontFamily_GetFontCount(This) \
	((This)->lpVtbl->GetFontCount(This))

#define IDWriteFontFamily_GetFont(This,index,font) \
	((This)->lpVtbl->GetFont(This,index,font))

#define IDWriteFontFamily_GetFamilyNames(This,names) \
	((This)->lpVtbl->GetFamilyNames(This,names))

#define IDWriteFontFamily_GetFirstMatchingFont(This,weight,stretch,style,matchingFont) \
	((This)->lpVtbl->GetFirstMatchingFont(This,weight,stretch,style,matchingFont))

#define IDWriteFontFamily_GetMatchingFonts(This,weight,stretch,style,matchingFonts) \
	((This)->lpVtbl->GetMatchingFonts(This,weight,stretch,style,matchingFonts))


struct IDWriteFontVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFont* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFont* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFont* This);

	STDMETHOD(GetFontFamily)(
		IDWriteFont* This,
		_COM_Outptr_ IDWriteFontFamily** fontFamily
		) PURE;

	STDMETHOD_(DWRITE_FONT_WEIGHT, GetWeight)(
		IDWriteFont* This) PURE;

	STDMETHOD_(DWRITE_FONT_STRETCH, GetStretch)(
		IDWriteFont* This) PURE;

	STDMETHOD_(DWRITE_FONT_STYLE, GetStyle)(
		IDWriteFont* This) PURE;

	STDMETHOD_(BOOL, IsSymbolFont)(
		IDWriteFont* This) PURE;

	STDMETHOD(GetFaceNames)(
		IDWriteFont* This,
		_COM_Outptr_ IDWriteLocalizedStrings** names
		) PURE;

	STDMETHOD(GetInformationalStrings)(
		IDWriteFont* This,
		DWRITE_INFORMATIONAL_STRING_ID informationalStringID,
		_COM_Outptr_result_maybenull_ IDWriteLocalizedStrings** informationalStrings,
		_Out_ BOOL* exists
		) PURE;

	STDMETHOD_(DWRITE_FONT_SIMULATIONS, GetSimulations)(
		IDWriteFont* This) PURE;

	STDMETHOD_(void, GetMetrics)(
		IDWriteFont* This,
		_Out_ DWRITE_FONT_METRICS* fontMetrics
		) PURE;

	STDMETHOD(HasCharacter)(
		IDWriteFont* This,
		UINT32 unicodeValue,
		_Out_ BOOL* exists
		) PURE;

	STDMETHOD(CreateFontFace)(
		IDWriteFont* This,
		_COM_Outptr_ IDWriteFontFace** fontFace
		) PURE;
};

interface IDWriteFont {
	struct IDWriteFontVtbl* lpVtbl;
};

#define IDWriteFont_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteFont_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteFont_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteFont_GetFontFamily(This,fontFamily) \
	((This)->lpVtbl->GetFontFamily(This,fontFamily))

#define IDWriteFont_GetWeight(This) \
	((This)->lpVtbl->GetWeight(This))

#define IDWriteFont_GetStretch(This) \
	((This)->lpVtbl->GetStretch(This))

#define IDWriteFont_GetStyle(This) \
	((This)->lpVtbl->GetStyle(This))

#define IDWriteFont_IsSymbolFont(This) \
	((This)->lpVtbl->IsSymbolFont(This))

#define IDWriteFont_GetFaceNames(This,names) \
	((This)->lpVtbl->GetFaceNames(This,names))

#define IDWriteFont_GetInformationalStrings(This,informationalStringID,informationalStrings,exists) \
	((This)->lpVtbl->GetInformationalStrings(This,informationalStringID,informationalStrings,exists))

#define IDWriteFont_GetSimulations(This) \
	((This)->lpVtbl->GetSimulations(This))

#define IDWriteFont_GetMetrics(This,fontMetrics) \
	((This)->lpVtbl->GetMetrics(This,fontMetrics))

#define IDWriteFont_HasCharacter(This,unicodeValue,exists) \
	((This)->lpVtbl->HasCharacter(This,unicodeValue,exists))

#define IDWriteFont_CreateFontFace(This,fontFace) \
	((This)->lpVtbl->CreateFontFace(This,fontFace))


typedef enum DWRITE_READING_DIRECTION {
	/// <summary>
	/// Reading progresses from left to right.
	/// </summary>
	DWRITE_READING_DIRECTION_LEFT_TO_RIGHT = 0,

	/// <summary>
	/// Reading progresses from right to left.
	/// </summary>
	DWRITE_READING_DIRECTION_RIGHT_TO_LEFT = 1,

	/// <summary>
	/// Reading progresses from top to bottom.
	/// </summary>
	DWRITE_READING_DIRECTION_TOP_TO_BOTTOM = 2,

	/// <summary>
	/// Reading progresses from bottom to top.
	/// </summary>
	DWRITE_READING_DIRECTION_BOTTOM_TO_TOP = 3,
} DWRITE_READING_DIRECTION;

/// <summary>
/// Direction for how lines of text are placed relative to one another.
/// </summary>
typedef enum DWRITE_FLOW_DIRECTION {
	/// <summary>
	/// Text lines are placed from top to bottom.
	/// </summary>
	DWRITE_FLOW_DIRECTION_TOP_TO_BOTTOM = 0,

	/// <summary>
	/// Text lines are placed from bottom to top.
	/// </summary>
	DWRITE_FLOW_DIRECTION_BOTTOM_TO_TOP = 1,

	/// <summary>
	/// Text lines are placed from left to right.
	/// </summary>
	DWRITE_FLOW_DIRECTION_LEFT_TO_RIGHT = 2,

	/// <summary>
	/// Text lines are placed from right to left.
	/// </summary>
	DWRITE_FLOW_DIRECTION_RIGHT_TO_LEFT = 3,
} DWRITE_FLOW_DIRECTION;

/// <summary>
/// Alignment of paragraph text along the reading direction axis relative to
/// the leading and trailing edge of the layout box.
/// </summary>
typedef enum DWRITE_TEXT_ALIGNMENT {
	/// <summary>
	/// The leading edge of the paragraph text is aligned to the layout box's leading edge.
	/// </summary>
	DWRITE_TEXT_ALIGNMENT_LEADING,

	/// <summary>
	/// The trailing edge of the paragraph text is aligned to the layout box's trailing edge.
	/// </summary>
	DWRITE_TEXT_ALIGNMENT_TRAILING,

	/// <summary>
	/// The center of the paragraph text is aligned to the center of the layout box.
	/// </summary>
	DWRITE_TEXT_ALIGNMENT_CENTER,

	/// <summary>
	/// Align text to the leading side, and also justify text to fill the lines.
	/// </summary>
	DWRITE_TEXT_ALIGNMENT_JUSTIFIED
} DWRITE_TEXT_ALIGNMENT;

/// <summary>
/// Alignment of paragraph text along the flow direction axis relative to the
/// flow's beginning and ending edge of the layout box.
/// </summary>
typedef enum DWRITE_PARAGRAPH_ALIGNMENT {
	/// <summary>
	/// The first line of paragraph is aligned to the flow's beginning edge of the layout box.
	/// </summary>
	DWRITE_PARAGRAPH_ALIGNMENT_NEAR,

	/// <summary>
	/// The last line of paragraph is aligned to the flow's ending edge of the layout box.
	/// </summary>
	DWRITE_PARAGRAPH_ALIGNMENT_FAR,

	/// <summary>
	/// The center of the paragraph is aligned to the center of the flow of the layout box.
	/// </summary>
	DWRITE_PARAGRAPH_ALIGNMENT_CENTER
} DWRITE_PARAGRAPH_ALIGNMENT;

/// <summary>
/// Word wrapping in multiline paragraph.
/// </summary>
typedef enum DWRITE_WORD_WRAPPING {
	/// <summary>
	/// Words are broken across lines to avoid text overflowing the layout box.
	/// </summary>
	DWRITE_WORD_WRAPPING_WRAP = 0,

	/// <summary>
	/// Words are kept within the same line even when it overflows the layout box.
	/// This option is often used with scrolling to reveal overflow text.
	/// </summary>
	DWRITE_WORD_WRAPPING_NO_WRAP = 1,

	/// <summary>
	/// Words are broken across lines to avoid text overflowing the layout box.
	/// Emergency wrapping occurs if the word is larger than the maximum width.
	/// </summary>
	DWRITE_WORD_WRAPPING_EMERGENCY_BREAK = 2,

	/// <summary>
	/// Only wrap whole words, never breaking words (emergency wrapping) when the
	/// layout width is too small for even a single word.
	/// </summary>
	DWRITE_WORD_WRAPPING_WHOLE_WORD = 3,

	/// <summary>
	/// Wrap between any valid characters clusters.
	/// </summary>
	DWRITE_WORD_WRAPPING_CHARACTER = 4,
} DWRITE_WORD_WRAPPING;

/// <summary>
/// The method used for line spacing in layout.
/// </summary>
typedef enum DWRITE_LINE_SPACING_METHOD {
	/// <summary>
	/// Line spacing depends solely on the content, growing to accommodate the size of fonts and inline objects.
	/// </summary>
	DWRITE_LINE_SPACING_METHOD_DEFAULT,

	/// <summary>
	/// Lines are explicitly set to uniform spacing, regardless of contained font sizes.
	/// This can be useful to avoid the uneven appearance that can occur from font fallback.
	/// </summary>
	DWRITE_LINE_SPACING_METHOD_UNIFORM,

	/// <summary>
	/// Line spacing and baseline distances are proportional to the computed values based on the content, the size of the fonts and inline objects.
	/// </summary>
	DWRITE_LINE_SPACING_METHOD_PROPORTIONAL
} DWRITE_LINE_SPACING_METHOD;

/// <summary>
/// Text granularity used to trim text overflowing the layout box.
/// </summary>
typedef enum DWRITE_TRIMMING_GRANULARITY {
	/// <summary>
	/// No trimming occurs. Text flows beyond the layout width.
	/// </summary>
	DWRITE_TRIMMING_GRANULARITY_NONE,

	/// <summary>
	/// Trimming occurs at character cluster boundary.
	/// </summary>
	DWRITE_TRIMMING_GRANULARITY_CHARACTER,

	/// <summary>
	/// Trimming occurs at word boundary.
	/// </summary>
	DWRITE_TRIMMING_GRANULARITY_WORD
} DWRITE_TRIMMING_GRANULARITY;

/// <summary>
/// Typographic feature of text supplied by the font.
/// </summary>
/// <remarks>
/// Use DWRITE_MAKE_FONT_FEATURE_TAG() to create a custom one.
/// <remarks>
typedef enum DWRITE_FONT_FEATURE_TAG {
	DWRITE_FONT_FEATURE_TAG_ALTERNATIVE_FRACTIONS = DWRITE_MAKE_OPENTYPE_TAG('a', 'f', 'r', 'c'),
	DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS_FROM_CAPITALS = DWRITE_MAKE_OPENTYPE_TAG('c', '2', 'p', 'c'),
	DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS_FROM_CAPITALS = DWRITE_MAKE_OPENTYPE_TAG('c', '2', 's', 'c'),
	DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_ALTERNATES = DWRITE_MAKE_OPENTYPE_TAG('c', 'a', 'l', 't'),
	DWRITE_FONT_FEATURE_TAG_CASE_SENSITIVE_FORMS = DWRITE_MAKE_OPENTYPE_TAG('c', 'a', 's', 'e'),
	DWRITE_FONT_FEATURE_TAG_GLYPH_COMPOSITION_DECOMPOSITION = DWRITE_MAKE_OPENTYPE_TAG('c', 'c', 'm', 'p'),
	DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_LIGATURES = DWRITE_MAKE_OPENTYPE_TAG('c', 'l', 'i', 'g'),
	DWRITE_FONT_FEATURE_TAG_CAPITAL_SPACING = DWRITE_MAKE_OPENTYPE_TAG('c', 'p', 's', 'p'),
	DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_SWASH = DWRITE_MAKE_OPENTYPE_TAG('c', 's', 'w', 'h'),
	DWRITE_FONT_FEATURE_TAG_CURSIVE_POSITIONING = DWRITE_MAKE_OPENTYPE_TAG('c', 'u', 'r', 's'),
	DWRITE_FONT_FEATURE_TAG_DEFAULT = DWRITE_MAKE_OPENTYPE_TAG('d', 'f', 'l', 't'),
	DWRITE_FONT_FEATURE_TAG_DISCRETIONARY_LIGATURES = DWRITE_MAKE_OPENTYPE_TAG('d', 'l', 'i', 'g'),
	DWRITE_FONT_FEATURE_TAG_EXPERT_FORMS = DWRITE_MAKE_OPENTYPE_TAG('e', 'x', 'p', 't'),
	DWRITE_FONT_FEATURE_TAG_FRACTIONS = DWRITE_MAKE_OPENTYPE_TAG('f', 'r', 'a', 'c'),
	DWRITE_FONT_FEATURE_TAG_FULL_WIDTH = DWRITE_MAKE_OPENTYPE_TAG('f', 'w', 'i', 'd'),
	DWRITE_FONT_FEATURE_TAG_HALF_FORMS = DWRITE_MAKE_OPENTYPE_TAG('h', 'a', 'l', 'f'),
	DWRITE_FONT_FEATURE_TAG_HALANT_FORMS = DWRITE_MAKE_OPENTYPE_TAG('h', 'a', 'l', 'n'),
	DWRITE_FONT_FEATURE_TAG_ALTERNATE_HALF_WIDTH = DWRITE_MAKE_OPENTYPE_TAG('h', 'a', 'l', 't'),
	DWRITE_FONT_FEATURE_TAG_HISTORICAL_FORMS = DWRITE_MAKE_OPENTYPE_TAG('h', 'i', 's', 't'),
	DWRITE_FONT_FEATURE_TAG_HORIZONTAL_KANA_ALTERNATES = DWRITE_MAKE_OPENTYPE_TAG('h', 'k', 'n', 'a'),
	DWRITE_FONT_FEATURE_TAG_HISTORICAL_LIGATURES = DWRITE_MAKE_OPENTYPE_TAG('h', 'l', 'i', 'g'),
	DWRITE_FONT_FEATURE_TAG_HALF_WIDTH = DWRITE_MAKE_OPENTYPE_TAG('h', 'w', 'i', 'd'),
	DWRITE_FONT_FEATURE_TAG_HOJO_KANJI_FORMS = DWRITE_MAKE_OPENTYPE_TAG('h', 'o', 'j', 'o'),
	DWRITE_FONT_FEATURE_TAG_JIS04_FORMS = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '0', '4'),
	DWRITE_FONT_FEATURE_TAG_JIS78_FORMS = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '7', '8'),
	DWRITE_FONT_FEATURE_TAG_JIS83_FORMS = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '8', '3'),
	DWRITE_FONT_FEATURE_TAG_JIS90_FORMS = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '9', '0'),
	DWRITE_FONT_FEATURE_TAG_KERNING = DWRITE_MAKE_OPENTYPE_TAG('k', 'e', 'r', 'n'),
	DWRITE_FONT_FEATURE_TAG_STANDARD_LIGATURES = DWRITE_MAKE_OPENTYPE_TAG('l', 'i', 'g', 'a'),
	DWRITE_FONT_FEATURE_TAG_LINING_FIGURES = DWRITE_MAKE_OPENTYPE_TAG('l', 'n', 'u', 'm'),
	DWRITE_FONT_FEATURE_TAG_LOCALIZED_FORMS = DWRITE_MAKE_OPENTYPE_TAG('l', 'o', 'c', 'l'),
	DWRITE_FONT_FEATURE_TAG_MARK_POSITIONING = DWRITE_MAKE_OPENTYPE_TAG('m', 'a', 'r', 'k'),
	DWRITE_FONT_FEATURE_TAG_MATHEMATICAL_GREEK = DWRITE_MAKE_OPENTYPE_TAG('m', 'g', 'r', 'k'),
	DWRITE_FONT_FEATURE_TAG_MARK_TO_MARK_POSITIONING = DWRITE_MAKE_OPENTYPE_TAG('m', 'k', 'm', 'k'),
	DWRITE_FONT_FEATURE_TAG_ALTERNATE_ANNOTATION_FORMS = DWRITE_MAKE_OPENTYPE_TAG('n', 'a', 'l', 't'),
	DWRITE_FONT_FEATURE_TAG_NLC_KANJI_FORMS = DWRITE_MAKE_OPENTYPE_TAG('n', 'l', 'c', 'k'),
	DWRITE_FONT_FEATURE_TAG_OLD_STYLE_FIGURES = DWRITE_MAKE_OPENTYPE_TAG('o', 'n', 'u', 'm'),
	DWRITE_FONT_FEATURE_TAG_ORDINALS = DWRITE_MAKE_OPENTYPE_TAG('o', 'r', 'd', 'n'),
	DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_ALTERNATE_WIDTH = DWRITE_MAKE_OPENTYPE_TAG('p', 'a', 'l', 't'),
	DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS = DWRITE_MAKE_OPENTYPE_TAG('p', 'c', 'a', 'p'),
	DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_FIGURES = DWRITE_MAKE_OPENTYPE_TAG('p', 'n', 'u', 'm'),
	DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_WIDTHS = DWRITE_MAKE_OPENTYPE_TAG('p', 'w', 'i', 'd'),
	DWRITE_FONT_FEATURE_TAG_QUARTER_WIDTHS = DWRITE_MAKE_OPENTYPE_TAG('q', 'w', 'i', 'd'),
	DWRITE_FONT_FEATURE_TAG_REQUIRED_LIGATURES = DWRITE_MAKE_OPENTYPE_TAG('r', 'l', 'i', 'g'),
	DWRITE_FONT_FEATURE_TAG_RUBY_NOTATION_FORMS = DWRITE_MAKE_OPENTYPE_TAG('r', 'u', 'b', 'y'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_ALTERNATES = DWRITE_MAKE_OPENTYPE_TAG('s', 'a', 'l', 't'),
	DWRITE_FONT_FEATURE_TAG_SCIENTIFIC_INFERIORS = DWRITE_MAKE_OPENTYPE_TAG('s', 'i', 'n', 'f'),
	DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS = DWRITE_MAKE_OPENTYPE_TAG('s', 'm', 'c', 'p'),
	DWRITE_FONT_FEATURE_TAG_SIMPLIFIED_FORMS = DWRITE_MAKE_OPENTYPE_TAG('s', 'm', 'p', 'l'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_1 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '1'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_2 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '2'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_3 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '3'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_4 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '4'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_5 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '5'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_6 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '6'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_7 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '7'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_8 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '8'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_9 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '9'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_10 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '0'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_11 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '1'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_12 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '2'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_13 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '3'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_14 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '4'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_15 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '5'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_16 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '6'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_17 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '7'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_18 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '8'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_19 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '9'),
	DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_20 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '2', '0'),
	DWRITE_FONT_FEATURE_TAG_SUBSCRIPT = DWRITE_MAKE_OPENTYPE_TAG('s', 'u', 'b', 's'),
	DWRITE_FONT_FEATURE_TAG_SUPERSCRIPT = DWRITE_MAKE_OPENTYPE_TAG('s', 'u', 'p', 's'),
	DWRITE_FONT_FEATURE_TAG_SWASH = DWRITE_MAKE_OPENTYPE_TAG('s', 'w', 's', 'h'),
	DWRITE_FONT_FEATURE_TAG_TITLING = DWRITE_MAKE_OPENTYPE_TAG('t', 'i', 't', 'l'),
	DWRITE_FONT_FEATURE_TAG_TRADITIONAL_NAME_FORMS = DWRITE_MAKE_OPENTYPE_TAG('t', 'n', 'a', 'm'),
	DWRITE_FONT_FEATURE_TAG_TABULAR_FIGURES = DWRITE_MAKE_OPENTYPE_TAG('t', 'n', 'u', 'm'),
	DWRITE_FONT_FEATURE_TAG_TRADITIONAL_FORMS = DWRITE_MAKE_OPENTYPE_TAG('t', 'r', 'a', 'd'),
	DWRITE_FONT_FEATURE_TAG_THIRD_WIDTHS = DWRITE_MAKE_OPENTYPE_TAG('t', 'w', 'i', 'd'),
	DWRITE_FONT_FEATURE_TAG_UNICASE = DWRITE_MAKE_OPENTYPE_TAG('u', 'n', 'i', 'c'),
	DWRITE_FONT_FEATURE_TAG_VERTICAL_WRITING = DWRITE_MAKE_OPENTYPE_TAG('v', 'e', 'r', 't'),
	DWRITE_FONT_FEATURE_TAG_VERTICAL_ALTERNATES_AND_ROTATION = DWRITE_MAKE_OPENTYPE_TAG('v', 'r', 't', '2'),
	DWRITE_FONT_FEATURE_TAG_SLASHED_ZERO = DWRITE_MAKE_OPENTYPE_TAG('z', 'e', 'r', 'o'),
} DWRITE_FONT_FEATURE_TAG;

/// <summary>
/// The DWRITE_TEXT_RANGE structure specifies a range of text positions where format is applied.
/// </summary>
typedef struct DWRITE_TEXT_RANGE {
	/// <summary>
	/// The start text position of the range.
	/// </summary>
	UINT32 startPosition;

	/// <summary>
	/// The number of text positions in the range.
	/// </summary>
	UINT32 length;
} DWRITE_TEXT_RANGE;

/// <summary>
/// The DWRITE_FONT_FEATURE structure specifies properties used to identify and execute typographic feature in the font.
/// </summary>
typedef struct DWRITE_FONT_FEATURE {
	/// <summary>
	/// The feature OpenType name identifier.
	/// </summary>
	DWRITE_FONT_FEATURE_TAG nameTag;

	/// <summary>
	/// Execution parameter of the feature.
	/// </summary>
	/// <remarks>
	/// The parameter should be non-zero to enable the feature.  Once enabled, a feature can't be disabled again within
	/// the same range.  Features requiring a selector use this value to indicate the selector index.
	/// </remarks>
	UINT32 parameter;
} DWRITE_FONT_FEATURE;

/// <summary>
/// Defines a set of typographic features to be applied during shaping.
/// Notice the character range which this feature list spans is specified
/// as a separate parameter to GetGlyphs.
/// </summary>
typedef struct DWRITE_TYPOGRAPHIC_FEATURES {
	/// <summary>
	/// Array of font features.
	/// </summary>
	_Field_size_(featureCount) DWRITE_FONT_FEATURE* features;

	/// <summary>
	/// The number of features.
	/// </summary>
	UINT32 featureCount;
} DWRITE_TYPOGRAPHIC_FEATURES;

/// <summary>
/// The DWRITE_TRIMMING structure specifies the trimming option for text overflowing the layout box.
/// </summary>
typedef struct DWRITE_TRIMMING {
	/// <summary>
	/// Text granularity of which trimming applies.
	/// </summary>
	DWRITE_TRIMMING_GRANULARITY granularity;

	/// <summary>
	/// Character code used as the delimiter signaling the beginning of the portion of text to be preserved,
	/// most useful for path ellipsis, where the delimiter would be a slash. Leave this zero if there is no
	/// delimiter.
	/// </summary>
	UINT32 delimiter;

	/// <summary>
	/// How many occurrences of the delimiter to step back. Leave this zero if there is no delimiter.
	/// </summary>
	UINT32 delimiterCount;
} DWRITE_TRIMMING;


struct IDWriteTextFormatVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteTextFormat* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteTextFormat* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteTextFormat* This);

	STDMETHOD(SetTextAlignment)(
		IDWriteTextFormat* This,
		DWRITE_TEXT_ALIGNMENT textAlignment
		) PURE;

	STDMETHOD(SetParagraphAlignment)(
		IDWriteTextFormat* This,
		DWRITE_PARAGRAPH_ALIGNMENT paragraphAlignment
		) PURE;

	STDMETHOD(SetWordWrapping)(
		IDWriteTextFormat* This,
		DWRITE_WORD_WRAPPING wordWrapping
		) PURE;

	STDMETHOD(SetReadingDirection)(
		IDWriteTextFormat* This,
		DWRITE_READING_DIRECTION readingDirection
		) PURE;

	STDMETHOD(SetFlowDirection)(
		IDWriteTextFormat* This,
		DWRITE_FLOW_DIRECTION flowDirection
		) PURE;

	STDMETHOD(SetIncrementalTabStop)(
		IDWriteTextFormat* This,
		FLOAT incrementalTabStop
		) PURE;

	STDMETHOD(SetTrimming)(
		IDWriteTextFormat* This,
		_In_ DWRITE_TRIMMING const* trimmingOptions,
		_In_opt_ IDWriteInlineObject* trimmingSign
		) PURE;

	STDMETHOD(SetLineSpacing)(
		IDWriteTextFormat* This,
		DWRITE_LINE_SPACING_METHOD lineSpacingMethod,
		FLOAT lineSpacing,
		FLOAT baseline
		) PURE;

	STDMETHOD_(DWRITE_TEXT_ALIGNMENT, GetTextAlignment)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD_(DWRITE_PARAGRAPH_ALIGNMENT, GetParagraphAlignment)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD_(DWRITE_WORD_WRAPPING, GetWordWrapping)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD_(DWRITE_READING_DIRECTION, GetReadingDirection)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD_(DWRITE_FLOW_DIRECTION, GetFlowDirection)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD_(FLOAT, GetIncrementalTabStop)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD(GetTrimming)(
		IDWriteTextFormat* This,
		_Out_ DWRITE_TRIMMING* trimmingOptions,
		_COM_Outptr_ IDWriteInlineObject** trimmingSign
		) PURE;

	STDMETHOD(GetLineSpacing)(
		IDWriteTextFormat* This,
		_Out_ DWRITE_LINE_SPACING_METHOD* lineSpacingMethod,
		_Out_ FLOAT* lineSpacing,
		_Out_ FLOAT* baseline
		) PURE;

	STDMETHOD(GetFontCollection)(
		IDWriteTextFormat* This,
		_COM_Outptr_ IDWriteFontCollection** fontCollection
		) PURE;

	STDMETHOD_(UINT32, GetFontFamilyNameLength)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD(GetFontFamilyName)(
		IDWriteTextFormat* This,
		_Out_writes_z_(nameSize) WCHAR* fontFamilyName,
		UINT32 nameSize
		) PURE;

	STDMETHOD_(DWRITE_FONT_WEIGHT, GetFontWeight)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD_(DWRITE_FONT_STYLE, GetFontStyle)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD_(DWRITE_FONT_STRETCH, GetFontStretch)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD_(FLOAT, GetFontSize)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD_(UINT32, GetLocaleNameLength)(
		IDWriteTextFormat* This) PURE;

	STDMETHOD(GetLocaleName)(
		IDWriteTextFormat* This,
		_Out_writes_z_(nameSize) WCHAR* localeName,
		UINT32 nameSize
		) PURE;
};

interface IDwriteTextFormat {
	struct IDWriteTextFormatVtbl* lpVtbl;
};

#define IDwriteTextFormat_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDwriteTextFormat_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDwriteTextFormat_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDwriteTextFormat_SetTextAlignment(This,textAlignment) \
	((This)->lpVtbl->SetTextAlignment(This,textAlignment))

#define IDwriteTextFormat_SetParagraphAlignment(This,paragraphAlignment) \
	((This)->lpVtbl->SetParagraphAlignment(This,paragraphAlignment))

#define IDwriteTextFormat_SetWordWrapping(This,wordWrapping) \
	((This)->lpVtbl->SetWordWrapping(This,wordWrapping))

#define IDwriteTextFormat_SetReadingDirection(This,readingDirection) \
	((This)->lpVtbl->SetReadingDirection(This,readingDirection))

#define IDwriteTextFormat_SetFlowDirection(This,flowDirection) \
	((This)->lpVtbl->SetFlowDirection(This,flowDirection))

#define IDwriteTextFormat_SetIncrementalTabStop(This,incrementalTabStop) \
	((This)->lpVtbl->SetIncrementalTabStop(This,incrementalTabStop))

#define IDwriteTextFormat_SetTrimming(This,trimmingOptions,trimmingSign) \
	((This)->lpVtbl->SetTrimming(This,trimmingOptions,trimmingSign))

#define IDwriteTextFormat_SetLineSpacing(This,lineSpacingMethod,lineSpacing,baseline) \
	((This)->lpVtbl->SetLineSpacing(This,lineSpacingMethod,lineSpacing,baseline))

#define IDwriteTextFormat_GetTextAlignment(This) \
	((This)->lpVtbl->GetTextAlignment(This))

#define IDwriteTextFormat_GetParagraphAlignment(This) \
	((This)->lpVtbl->GetParagraphAlignment(This))

#define IDwriteTextFormat_GetWordWrapping(This) \
	((This)->lpVtbl->GetWordWrapping(This))

#define IDwriteTextFormat_GetReadingDirection(This) \
	((This)->lpVtbl->GetReadingDirection(This))

#define IDwriteTextFormat_GetFlowDirection(This) \
	((This)->lpVtbl->GetFlowDirection(This))

#define IDwriteTextFormat_GetIncrementalTabStop(This) \
	((This)->lpVtbl->GetIncrementalTabStop(This))

#define IDwriteTextFormat_GetTrimming(This,trimmingOptions,trimmingSign) \
	((This)->lpVtbl->GetTrimming(This,trimmingOptions,trimmingSign))

#define IDwriteTextFormat_GetLineSpacing(This,lineSpacingMethod,lineSpacing,baseline) \
	((This)->lpVtbl->GetLineSpacing(This,lineSpacingMethod,lineSpacing,baseline))

#define IDwriteTextFormat_GetFontCollection(This,fontCollection) \
	((This)->lpVtbl->GetFontCollection(This,fontCollection))

#define IDwriteTextFormat_GetFontFamilyNameLength(This) \
	((This)->lpVtbl->GetFontFamilyNameLength(This))

#define IDwriteTextFormat_GetFontFamilyName(This,fontFamilyName,nameSize) \
	((This)->lpVtbl->GetFontFamilyName(This,fontFamilyName,nameSize))

#define IDwriteTextFormat_GetFontWeight(This) \
	((This)->lpVtbl->GetFontWeight(This))

#define IDwriteTextFormat_GetFontStyle(This) \
	((This)->lpVtbl->GetFontStyle(This))

#define IDwriteTextFormat_GetFontStretch(This) \
	((This)->lpVtbl->GetFontStretch(This))

#define IDwriteTextFormat_GetFontSize(This) \
	((This)->lpVtbl->GetFontSize(This))

#define IDwriteTextFormat_GetLocaleNameLength(This) \
	((This)->lpVtbl->GetLocaleNameLength(This))

#define IDwriteTextFormat_GetLocaleName(This,localeName,nameSize) \
	((This)->lpVtbl->GetLocaleName(This,localeName,nameSize))


struct IDWriteTypographyVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteTypography* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteTypography* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteTypography* This);

	STDMETHOD(AddFontFeature)(
		IDWriteTypography* This,
		DWRITE_FONT_FEATURE fontFeature
		) PURE;

	STDMETHOD_(UINT32, GetFontFeatureCount)(
		IDWriteTypography* This) PURE;

	STDMETHOD(GetFontFeature)(
		IDWriteTypography* This,
		UINT32 fontFeatureIndex,
		_Out_ DWRITE_FONT_FEATURE* fontFeature
		) PURE;
};

interface IDwriteTypography {
	struct IDWriteTypographyVtbl* lpVtbl;
};

#define IDwriteTypography_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDwriteTypography_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDwriteTypography_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDwriteTypography_AddFontFeature(This,fontFeature) \
	((This)->lpVtbl->AddFontFeature(This,fontFeature))

#define IDwriteTypography_GetFontFeatureCount(This) \
	((This)->lpVtbl->GetFontFeatureCount(This))

#define IDwriteTypography_GetFontFeature(This,fontFeatureIndex,fontFeature) \
	((This)->lpVtbl->GetFontFeature(This,fontFeatureIndex,fontFeature))


typedef enum DWRITE_SCRIPT_SHAPES {
	/// <summary>
	/// No additional shaping requirement. Text is shaped with the writing system default behavior.
	/// </summary>
	DWRITE_SCRIPT_SHAPES_DEFAULT = 0,

	/// <summary>
	/// Text should leave no visual on display i.e. control or format control characters.
	/// </summary>
	DWRITE_SCRIPT_SHAPES_NO_VISUAL = 1
} DWRITE_SCRIPT_SHAPES;

/// <summary>
/// Association of text and its writing system script as well as some display attributes.
/// </summary>
typedef struct DWRITE_SCRIPT_ANALYSIS {
	/// <summary>
	/// Zero-based index representation of writing system script.
	/// </summary>
	UINT16 script;

	/// <summary>
	/// Additional shaping requirement of text.
	/// </summary>
	DWRITE_SCRIPT_SHAPES shapes;
} DWRITE_SCRIPT_ANALYSIS;

/// <summary>
/// Condition at the edges of inline object or text used to determine
/// line-breaking behavior.
/// </summary>
typedef enum DWRITE_BREAK_CONDITION {
	/// <summary>
	/// Whether a break is allowed is determined by the condition of the
	/// neighboring text span or inline object.
	/// </summary>
	DWRITE_BREAK_CONDITION_NEUTRAL,

	/// <summary>
	/// A break is allowed, unless overruled by the condition of the
	/// neighboring text span or inline object, either prohibited by a
	/// May Not or forced by a Must.
	/// </summary>
	DWRITE_BREAK_CONDITION_CAN_BREAK,

	/// <summary>
	/// There should be no break, unless overruled by a Must condition from
	/// the neighboring text span or inline object.
	/// </summary>
	DWRITE_BREAK_CONDITION_MAY_NOT_BREAK,

	/// <summary>
	/// The break must happen, regardless of the condition of the adjacent
	/// text span or inline object.
	/// </summary>
	DWRITE_BREAK_CONDITION_MUST_BREAK
} DWRITE_BREAK_CONDITION;

/// <summary>
/// Line breakpoint characteristics of a character.
/// </summary>
typedef struct DWRITE_LINE_BREAKPOINT {
	/// <summary>
	/// Breaking condition before the character.
	/// </summary>
	UINT8 breakConditionBefore : 2;

	/// <summary>
	/// Breaking condition after the character.
	/// </summary>
	UINT8 breakConditionAfter : 2;

	/// <summary>
	/// The character is some form of whitespace, which may be meaningful
	/// for justification.
	/// </summary>
	UINT8 isWhitespace : 1;

	/// <summary>
	/// The character is a soft hyphen, often used to indicate hyphenation
	/// points inside words.
	/// </summary>
	UINT8 isSoftHyphen : 1;

	UINT8 padding : 2;
} DWRITE_LINE_BREAKPOINT;

/// <summary>
/// How to apply number substitution on digits and related punctuation.
/// </summary>
typedef enum DWRITE_NUMBER_SUBSTITUTION_METHOD {
	/// <summary>
	/// Specifies that the substitution method should be determined based
	/// on LOCALE_IDIGITSUBSTITUTION value of the specified text culture.
	/// </summary>
	DWRITE_NUMBER_SUBSTITUTION_METHOD_FROM_CULTURE,

	/// <summary>
	/// If the culture is Arabic or Farsi, specifies that the number shape
	/// depend on the context. Either traditional or nominal number shape
	/// are used depending on the nearest preceding strong character or (if
	/// there is none) the reading direction of the paragraph.
	/// </summary>
	DWRITE_NUMBER_SUBSTITUTION_METHOD_CONTEXTUAL,

	/// <summary>
	/// Specifies that code points 0x30-0x39 are always rendered as nominal numeral
	/// shapes (ones of the European number), i.e., no substitution is performed.
	/// </summary>
	DWRITE_NUMBER_SUBSTITUTION_METHOD_NONE,

	/// <summary>
	/// Specifies that number are rendered using the national number shape
	/// as specified by the LOCALE_SNATIVEDIGITS value of the specified text culture.
	/// </summary>
	DWRITE_NUMBER_SUBSTITUTION_METHOD_NATIONAL,

	/// <summary>
	/// Specifies that number are rendered using the traditional shape
	/// for the specified culture. For most cultures, this is the same as
	/// NativeNational. However, NativeNational results in Latin number
	/// for some Arabic cultures, whereas this value results in Arabic
	/// number for all Arabic cultures.
	/// </summary>
	DWRITE_NUMBER_SUBSTITUTION_METHOD_TRADITIONAL
} DWRITE_NUMBER_SUBSTITUTION_METHOD;


struct IDWriteNumberSubstitutionVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteNumberSubstitution* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteNumberSubstitution* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteNumberSubstitution* This);
};

interface IDWriteNumberSubstitution {
	const struct IDWriteNumberSubstitutionVtbl* lpVtbl;
};

#define IDWriteNumberSubstitution_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteNumberSubstitution_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteNumberSubstitution_Release(This) \
	((This)->lpVtbl->Release(This))


typedef struct DWRITE_SHAPING_TEXT_PROPERTIES {
	/// <summary>
	/// This character can be shaped independently from the others
	/// (usually set for the space character).
	/// </summary>
	UINT16 isShapedAlone : 1;

	/// <summary>
	/// Reserved for use by shaping engine.
	/// </summary>
	UINT16 reserved1 : 1;

	/// <summary>
	/// Glyph shaping can be cut after this point without affecting shaping
	/// before or after it. Otherwise, splitting a call to GetGlyphs would
	/// cause a reflow of glyph advances and shapes.
	/// </summary>
	UINT16 canBreakShapingAfter : 1;

	/// <summary>
	/// Reserved for use by shaping engine.
	/// </summary>
	UINT16 reserved : 13;
} DWRITE_SHAPING_TEXT_PROPERTIES;

/// <summary>
/// Shaping output properties per output glyph.
/// </summary>
typedef struct DWRITE_SHAPING_GLYPH_PROPERTIES {
	/// <summary>
	/// Justification class, whether to use spacing, kashidas, or
	/// another method. This exists for backwards compatibility
	/// with Uniscribe's SCRIPT_JUSTIFY enum.
	/// </summary>
	UINT16 justification : 4;

	/// <summary>
	/// Indicates glyph is the first of a cluster.
	/// </summary>
	UINT16 isClusterStart : 1;

	/// <summary>
	/// Glyph is a diacritic.
	/// </summary>
	UINT16 isDiacritic : 1;

	/// <summary>
	/// Glyph has no width, mark, ZWJ, ZWNJ, ZWSP, LRM etc.
	/// This flag is not limited to just U+200B.
	/// </summary>
	UINT16 isZeroWidthSpace : 1;

	/// <summary>
	/// Reserved for use by shaping engine.
	/// </summary>
	UINT16 reserved : 9;
} DWRITE_SHAPING_GLYPH_PROPERTIES;


struct IDWriteTextAnalysisSourceVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteTextAnalysisSource* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteTextAnalysisSource* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteTextAnalysisSource* This);

	STDMETHOD(GetTextAtPosition)(
		IDWriteTextAnalysisSource* This,
		UINT32 textPosition,
		_Outptr_result_buffer_(*textLength) WCHAR const** textString,
		_Out_ UINT32* textLength
		) PURE;

	STDMETHOD(GetTextBeforePosition)(
		IDWriteTextAnalysisSource* This,
		UINT32 textPosition,
		_Outptr_result_buffer_(*textLength) WCHAR const** textString,
		_Out_ UINT32* textLength
		) PURE;

	STDMETHOD_(DWRITE_READING_DIRECTION, GetParagraphReadingDirection)(
		IDWriteTextAnalysisSource* This) PURE;

	STDMETHOD(GetLocaleName)(
		IDWriteTextAnalysisSource* This,
		UINT32 textPosition,
		_Out_ UINT32* textLength,
		_Outptr_result_z_ WCHAR const** localeName
		) PURE;

	STDMETHOD(GetNumberSubstitution)(
		IDWriteTextAnalysisSource* This,
		UINT32 textPosition,
		_Out_ UINT32* textLength,
		_COM_Outptr_ IDWriteNumberSubstitution** numberSubstitution
		) PURE;
};

interface IDWriteTextAnalysisSource {
	const struct IDWriteTextAnalysisSourceVtbl* lpVtbl;
};

#define IDWriteTextAnalysisSource_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteTextAnalysisSource_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteTextAnalysisSource_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteTextAnalysisSource_GetTextAtPosition(This,textPosition,textString,textLength) \
	((This)->lpVtbl->GetTextAtPosition(This,textPosition,textString,textLength))

#define IDWriteTextAnalysisSource_GetTextBeforePosition(This,textPosition,textString,textLength) \
	((This)->lpVtbl->GetTextBeforePosition(This,textPosition,textString,textLength))

#define IDWriteTextAnalysisSource_GetParagraphReadingDirection(This) \
	((This)->lpVtbl->GetParagraphReadingDirection(This))

#define IDWriteTextAnalysisSource_GetLocaleName(This,textPosition,textLength,localeName) \
	((This)->lpVtbl->GetLocaleName(This,textPosition,textLength,localeName))

#define IDWriteTextAnalysisSource_GetNumberSubstitution(This,textPosition,textLength,numberSubstitution) \
	((This)->lpVtbl->GetNumberSubstitution(This,textPosition,textLength,numberSubstitution))


struct IDWriteTextAnalysisSinkVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteTextAnalysisSink* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteTextAnalysisSink* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteTextAnalysisSink* This);

	STDMETHOD(SetScriptAnalysis)(
		IDWriteTextAnalysisSink* This,
		UINT32 textPosition,
		UINT32 textLength,
		_In_ DWRITE_SCRIPT_ANALYSIS const* scriptAnalysis
		) PURE;


	STDMETHOD(SetLineBreakpoints)(
		IDWriteTextAnalysisSink* This,
		UINT32 textPosition,
		UINT32 textLength,
		_In_reads_(textLength) DWRITE_LINE_BREAKPOINT const* lineBreakpoints
		) PURE;

	STDMETHOD(SetBidiLevel)(
		IDWriteTextAnalysisSink* This,
		UINT32 textPosition,
		UINT32 textLength,
		UINT8 explicitLevel,
		UINT8 resolvedLevel
		) PURE;

	STDMETHOD(SetNumberSubstitution)(
		IDWriteTextAnalysisSink* This,
		UINT32 textPosition,
		UINT32 textLength,
		_In_ IDWriteNumberSubstitution* numberSubstitution
		) PURE;
};

interface IDWriteTextAnalysisSink {
	const struct IDWriteTextAnalysisSinkVtbl* lpVtbl;
};

#define IDWriteTextAnalysisSink_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteTextAnalysisSink_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteTextAnalysisSink_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteTextAnalysisSink_SetScriptAnalysis(This,textPosition,textLength,scriptAnalysis) \
	((This)->lpVtbl->SetScriptAnalysis(This,textPosition,textLength,scriptAnalysis))

#define IDWriteTextAnalysisSink_SetLineBreakpoints(This,textPosition,textLength,lineBreakpoints) \
	((This)->lpVtbl->SetLineBreakpoints(This,textPosition,textLength,lineBreakpoints))

#define IDWriteTextAnalysisSink_SetBidiLevel(This,textPosition,textLength,explicitLevel,resolvedLevel) \
	((This)->lpVtbl->SetBidiLevel(This,textPosition,textLength,explicitLevel,resolvedLevel))

#define IDWriteTextAnalysisSink_SetNumberSubstitution(This,textPosition,textLength,numberSubstitution) \
	((This)->lpVtbl->SetNumberSubstitution(This,textPosition,textLength,numberSubstitution))


struct IDWriteTextAnalyzerVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteTextAnalyzer* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteTextAnalyzer* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteTextAnalyzer* This);

	STDMETHOD(AnalyzeScript)(
		IDWriteTextAnalyzer* This,
		_In_ IDWriteTextAnalysisSource* analysisSource,
		UINT32 textPosition,
		UINT32 textLength,
		_In_ IDWriteTextAnalysisSink* analysisSink
		) PURE;

	STDMETHOD(AnalyzeBidi)(
		IDWriteTextAnalyzer* This,
		_In_ IDWriteTextAnalysisSource* analysisSource,
		UINT32 textPosition,
		UINT32 textLength,
		_In_ IDWriteTextAnalysisSink* analysisSink
		) PURE;

	STDMETHOD(AnalyzeNumberSubstitution)(
		IDWriteTextAnalyzer* This,
		_In_ IDWriteTextAnalysisSource* analysisSource,
		UINT32 textPosition,
		UINT32 textLength,
		_In_ IDWriteTextAnalysisSink* analysisSink
		) PURE;

	STDMETHOD(AnalyzeLineBreakpoints)(
		IDWriteTextAnalyzer* This,
		_In_ IDWriteTextAnalysisSource* analysisSource,
		UINT32 textPosition,
		UINT32 textLength,
		_In_ IDWriteTextAnalysisSink* analysisSink
		) PURE;

	STDMETHOD(GetGlyphs)(
		IDWriteTextAnalyzer* This,
		_In_reads_(textLength) WCHAR const* textString,
		UINT32 textLength,
		_In_ IDWriteFontFace* fontFace,
		BOOL isSideways,
		BOOL isRightToLeft,
		_In_ DWRITE_SCRIPT_ANALYSIS const* scriptAnalysis,
		_In_opt_z_ WCHAR const* localeName,
		_In_opt_ IDWriteNumberSubstitution* numberSubstitution,
		_In_reads_opt_(featureRanges) DWRITE_TYPOGRAPHIC_FEATURES const** features,
		_In_reads_opt_(featureRanges) UINT32 const* featureRangeLengths,
		UINT32 featureRanges,
		UINT32 maxGlyphCount,
		_Out_writes_(textLength) UINT16* clusterMap,
		_Out_writes_(textLength) DWRITE_SHAPING_TEXT_PROPERTIES* textProps,
		_Out_writes_(maxGlyphCount) UINT16* glyphIndices,
		_Out_writes_(maxGlyphCount) DWRITE_SHAPING_GLYPH_PROPERTIES* glyphProps,
		_Out_ UINT32* actualGlyphCount
		) PURE;

	STDMETHOD(GetGlyphPlacements)(
		IDWriteTextAnalyzer* This,
		_In_reads_(textLength) WCHAR const* textString,
		_In_reads_(textLength) UINT16 const* clusterMap,
		_Inout_updates_(textLength) DWRITE_SHAPING_TEXT_PROPERTIES* textProps,
		UINT32 textLength,
		_In_reads_(glyphCount) UINT16 const* glyphIndices,
		_In_reads_(glyphCount) DWRITE_SHAPING_GLYPH_PROPERTIES const* glyphProps,
		UINT32 glyphCount,
		_In_ IDWriteFontFace* fontFace,
		FLOAT fontEmSize,
		BOOL isSideways,
		BOOL isRightToLeft,
		_In_ DWRITE_SCRIPT_ANALYSIS const* scriptAnalysis,
		_In_opt_z_ WCHAR const* localeName,
		_In_reads_opt_(featureRanges) DWRITE_TYPOGRAPHIC_FEATURES const** features,
		_In_reads_opt_(featureRanges) UINT32 const* featureRangeLengths,
		UINT32 featureRanges,
		_Out_writes_(glyphCount) FLOAT* glyphAdvances,
		_Out_writes_(glyphCount) DWRITE_GLYPH_OFFSET* glyphOffsets
		) PURE;

	STDMETHOD(GetGdiCompatibleGlyphPlacements)(
		IDWriteTextAnalyzer* This,
		_In_reads_(textLength) WCHAR const* textString,
		_In_reads_(textLength) UINT16 const* clusterMap,
		_In_reads_(textLength) DWRITE_SHAPING_TEXT_PROPERTIES* textProps,
		UINT32 textLength,
		_In_reads_(glyphCount) UINT16 const* glyphIndices,
		_In_reads_(glyphCount) DWRITE_SHAPING_GLYPH_PROPERTIES const* glyphProps,
		UINT32 glyphCount,
		_In_ IDWriteFontFace* fontFace,
		FLOAT fontEmSize,
		FLOAT pixelsPerDip,
		_In_opt_ DWRITE_MATRIX const* transform,
		BOOL useGdiNatural,
		BOOL isSideways,
		BOOL isRightToLeft,
		_In_ DWRITE_SCRIPT_ANALYSIS const* scriptAnalysis,
		_In_opt_z_ WCHAR const* localeName,
		_In_reads_opt_(featureRanges) DWRITE_TYPOGRAPHIC_FEATURES const** features,
		_In_reads_opt_(featureRanges) UINT32 const* featureRangeLengths,
		UINT32 featureRanges,
		_Out_writes_(glyphCount) FLOAT* glyphAdvances,
		_Out_writes_(glyphCount) DWRITE_GLYPH_OFFSET* glyphOffsets
		) PURE;
};

interface IDWriteTextAnalyzer {
	struct IDWriteTextAnalyzerVtbl* lpVtbl;
};

#define IDWriteTextAnalyzer_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteTextAnalyzer_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteTextAnalyzer_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteTextAnalyzer_AnalyzeScript(This,analysisSource,textPosition,textLength,analysisSink) \
	((This)->lpVtbl->AnalyzeScript(This,analysisSource,textPosition,textLength,analysisSink))

#define IDWriteTextAnalyzer_AnalyzeBidi(This,analysisSource,textPosition,textLength,analysisSink) \
	((This)->lpVtbl->AnalyzeBidi(This,analysisSource,textPosition,textLength,analysisSink))

#define IDWriteTextAnalyzer_AnalyzeNumberSubstitution(This,analysisSource,textPosition,textLength,analysisSink) \
	((This)->lpVtbl->AnalyzeNumberSubstitution(This,analysisSource,textPosition,textLength,analysisSink))

#define IDWriteTextAnalyzer_AnalyzeLineBreakpoints(This,analysisSource,textPosition,textLength,analysisSink) \
	((This)->lpVtbl->AnalyzeLineBreakpoints(This,analysisSource,textPosition,textLength,analysisSink))

#define IDWriteTextAnalyzer_GetGlyphs(This,textString,textLength,fontFace,isSideways,isRightToLeft,scriptAnalysis,localeName,numberSubstitution,features,featureRangeLengths,featureRanges,maxGlyphCount,clusterMap,textProps,glyphIndices,glyphProps,actualGlyphCount) \
	((This)->lpVtbl->GetGlyphs(This,textString,textLength,fontFace,isSideways,isRightToLeft,scriptAnalysis,localeName,numberSubstitution,features,featureRangeLengths,featureRanges,maxGlyphCount,clusterMap,textProps,glyphIndices,glyphProps,actualGlyphCount))

#define IDWriteTextAnalyzer_GetGdiCompatibleGlyphs(This,textString,textLength,fontFace,fontEmSize,pixelsPerDip,transform,useGdiNatural,isSideways,isRightToLeft,scriptAnalysis,localeName,numberSubstitution,features,featureRangeLengths,featureRanges,maxGlyphCount,clusterMap,textProps,glyphIndices,glyphProps,actualGlyphCount,glyphAdvances,glyphOffsets) \
	((This)->lpVtbl->GetGdiCompatibleGlyphs(This,textString,textLength,fontFace,fontEmSize,pixelsPerDip,transform,useGdiNatural,isSideways,isRightToLeft,scriptAnalysis,localeName,numberSubstitution,features,featureRangeLengths,featureRanges,maxGlyphCount,clusterMap,textProps,glyphIndices,glyphProps,actualGlyphCount,glyphAdvances,glyphOffsets))

#define IDWriteTextAnalyzer_GetGlyphPlacements(This,textString,clusterMap,textProps,textLength,glyphIndices,glyphProps,glyphCount,fontFace,fontEmSize,isSideways,isRightToLeft,scriptAnalysis,localeName,features,featureRangeLengths,featureRanges,glyphAdvances,glyphOffsets) \
	((This)->lpVtbl->GetGlyphPlacements(This,textString,clusterMap,textProps,textLength,glyphIndices,glyphProps,glyphCount,fontFace,fontEmSize,isSideways,isRightToLeft,scriptAnalysis,localeName,features,featureRangeLengths,featureRanges,glyphAdvances,glyphOffsets))

#define IDWriteTextAnalyzer_GetGdiCompatibleGlyphPlacements(This,textString,clusterMap,textProps,textLength,glyphIndices,glyphProps,glyphCount,fontFace,fontEmSize,pixelsPerDip,transform,useGdiNatural,isSideways,isRightToLeft,scriptAnalysis,localeName,features,featureRangeLengths,featureRanges,glyphAdvances,glyphOffsets) \
	((This)->lpVtbl->GetGdiCompatibleGlyphPlacements(This,textString,clusterMap,textProps,textLength,glyphIndices,glyphProps,glyphCount,fontFace,fontEmSize,pixelsPerDip,transform,useGdiNatural,isSideways,isRightToLeft,scriptAnalysis,localeName,features,featureRangeLengths,featureRanges,glyphAdvances,glyphOffsets))


typedef struct DWRITE_GLYPH_RUN {
	/// <summary>
	/// The physical font face to draw with.
	/// </summary>
	_Notnull_ IDWriteFontFace* fontFace;

	/// <summary>
	/// Logical size of the font in DIPs, not points (equals 1/96 inch).
	/// </summary>
	FLOAT fontEmSize;

	/// <summary>
	/// The number of glyphs.
	/// </summary>
	UINT32 glyphCount;

	/// <summary>
	/// The indices to render.
	/// </summary>
	_Field_size_(glyphCount) UINT16 const* glyphIndices;

	/// <summary>
	/// Glyph advance widths.
	/// </summary>
	_Field_size_opt_(glyphCount) FLOAT const* glyphAdvances;

	/// <summary>
	/// Glyph offsets.
	/// </summary>
	_Field_size_opt_(glyphCount) DWRITE_GLYPH_OFFSET const* glyphOffsets;

	/// <summary>
	/// If true, specifies that glyphs are rotated 90 degrees to the left and
	/// vertical metrics are used. Vertical writing is achieved by specifying
	/// isSideways = true and rotating the entire run 90 degrees to the right
	/// via a rotate transform.
	/// </summary>
	BOOL isSideways;

	/// <summary>
	/// The implicit resolved bidi level of the run. Odd levels indicate
	/// right-to-left languages like Hebrew and Arabic, while even levels
	/// indicate left-to-right languages like English and Japanese (when
	/// written horizontally). For right-to-left languages, the text origin
	/// is on the right, and text should be drawn to the left.
	/// </summary>
	UINT32 bidiLevel;
} DWRITE_GLYPH_RUN;

/// <summary>
/// The DWRITE_GLYPH_RUN_DESCRIPTION structure contains additional properties
/// related to those in DWRITE_GLYPH_RUN.
/// </summary>
typedef struct DWRITE_GLYPH_RUN_DESCRIPTION {
	/// <summary>
	/// The locale name associated with this run.
	/// </summary>
	_Field_z_ WCHAR const* localeName;

	/// <summary>
	/// The text associated with the glyphs.
	/// </summary>
	_Field_size_(stringLength) WCHAR const* string;

	/// <summary>
	/// The number of characters (UTF16 code-units).
	/// Note that this may be different than the number of glyphs.
	/// </summary>
	UINT32 stringLength;

	/// <summary>
	/// An array of indices to the glyph indices array, of the first glyphs of
	/// all the glyph clusters of the glyphs to render.
	/// </summary>
	_Field_size_opt_(stringLength) UINT16 const* clusterMap;

	/// <summary>
	/// Corresponding text position in the original string
	/// this glyph run came from.
	/// </summary>
	UINT32 textPosition;
} DWRITE_GLYPH_RUN_DESCRIPTION;

/// <summary>
/// The DWRITE_UNDERLINE structure contains information about the size and
/// placement of underlines. All coordinates are in device independent
/// pixels (DIPs).
/// </summary>
typedef struct DWRITE_UNDERLINE {
	/// <summary>
	/// Width of the underline, measured parallel to the baseline.
	/// </summary>
	FLOAT width;

	/// <summary>
	/// Thickness of the underline, measured perpendicular to the
	/// baseline.
	/// </summary>
	FLOAT thickness;

	/// <summary>
	/// Offset of the underline from the baseline.
	/// A positive offset represents a position below the baseline and
	/// a negative offset is above.
	/// </summary>
	FLOAT offset;

	/// <summary>
	/// Height of the tallest run where the underline applies.
	/// </summary>
	FLOAT runHeight;

	/// <summary>
	/// Reading direction of the text associated with the underline.  This
	/// value is used to interpret whether the width value runs horizontally
	/// or vertically.
	/// </summary>
	DWRITE_READING_DIRECTION readingDirection;

	/// <summary>
	/// Flow direction of the text associated with the underline.  This value
	/// is used to interpret whether the thickness value advances top to
	/// bottom, left to right, or right to left.
	/// </summary>
	DWRITE_FLOW_DIRECTION flowDirection;

	/// <summary>
	/// Locale of the text the underline is being drawn under. Can be
	/// pertinent where the locale affects how the underline is drawn.
	/// For example, in vertical text, the underline belongs on the
	/// left for Chinese but on the right for Japanese.
	/// This choice is completely left up to higher levels.
	/// </summary>
	_Field_z_ WCHAR const* localeName;

	/// <summary>
	/// The measuring mode can be useful to the renderer to determine how
	/// underlines are rendered, e.g. rounding the thickness to a whole pixel
	/// in GDI-compatible modes.
	/// </summary>
	DWRITE_MEASURING_MODE measuringMode;
} DWRITE_UNDERLINE;

/// <summary>
/// The DWRITE_STRIKETHROUGH structure contains information about the size and
/// placement of strikethroughs. All coordinates are in device independent
/// pixels (DIPs).
/// </summary>
typedef struct DWRITE_STRIKETHROUGH {
	/// <summary>
	/// Width of the strikethrough, measured parallel to the baseline.
	/// </summary>
	FLOAT width;

	/// <summary>
	/// Thickness of the strikethrough, measured perpendicular to the
	/// baseline.
	/// </summary>
	FLOAT thickness;

	/// <summary>
	/// Offset of the strikethrough from the baseline.
	/// A positive offset represents a position below the baseline and
	/// a negative offset is above.
	/// </summary>
	FLOAT offset;

	/// <summary>
	/// Reading direction of the text associated with the strikethrough.  This
	/// value is used to interpret whether the width value runs horizontally
	/// or vertically.
	/// </summary>
	DWRITE_READING_DIRECTION readingDirection;

	/// <summary>
	/// Flow direction of the text associated with the strikethrough.  This
	/// value is used to interpret whether the thickness value advances top to
	/// bottom, left to right, or right to left.
	/// </summary>
	DWRITE_FLOW_DIRECTION flowDirection;

	/// <summary>
	/// Locale of the range. Can be pertinent where the locale affects the style.
	/// </summary>
	_Field_z_ WCHAR const* localeName;

	/// <summary>
	/// The measuring mode can be useful to the renderer to determine how
	/// underlines are rendered, e.g. rounding the thickness to a whole pixel
	/// in GDI-compatible modes.
	/// </summary>
	DWRITE_MEASURING_MODE measuringMode;
} DWRITE_STRIKETHROUGH;

/// <summary>
/// The DWRITE_LINE_METRICS structure contains information about a formatted
/// line of text.
/// </summary>
typedef struct DWRITE_LINE_METRICS {
	/// <summary>
	/// The number of total text positions in the line.
	/// This includes any trailing whitespace and newline characters.
	/// </summary>
	UINT32 length;

	/// <summary>
	/// The number of whitespace positions at the end of the line.  Newline
	/// sequences are considered whitespace.
	/// </summary>
	UINT32 trailingWhitespaceLength;

	/// <summary>
	/// The number of characters in the newline sequence at the end of the line.
	/// If the count is zero, then the line was either wrapped or it is the
	/// end of the text.
	/// </summary>
	UINT32 newlineLength;

	/// <summary>
	/// Height of the line as measured from top to bottom.
	/// </summary>
	FLOAT height;

	/// <summary>
	/// Distance from the top of the line to its baseline.
	/// </summary>
	FLOAT baseline;

	/// <summary>
	/// The line is trimmed.
	/// </summary>
	BOOL isTrimmed;
} DWRITE_LINE_METRICS;


/// <summary>
/// The DWRITE_CLUSTER_METRICS structure contains information about a glyph cluster.
/// </summary>
typedef struct DWRITE_CLUSTER_METRICS {
	/// <summary>
	/// The total advance width of all glyphs in the cluster.
	/// </summary>
	FLOAT width;

	/// <summary>
	/// The number of text positions in the cluster.
	/// </summary>
	UINT16 length;

	/// <summary>
	/// Indicate whether line can be broken right after the cluster.
	/// </summary>
	UINT16 canWrapLineAfter : 1;

	/// <summary>
	/// Indicate whether the cluster corresponds to whitespace character.
	/// </summary>
	UINT16 isWhitespace : 1;

	/// <summary>
	/// Indicate whether the cluster corresponds to a newline character.
	/// </summary>
	UINT16 isNewline : 1;

	/// <summary>
	/// Indicate whether the cluster corresponds to soft hyphen character.
	/// </summary>
	UINT16 isSoftHyphen : 1;

	/// <summary>
	/// Indicate whether the cluster is read from right to left.
	/// </summary>
	UINT16 isRightToLeft : 1;

	UINT16 padding : 11;
} DWRITE_CLUSTER_METRICS;


/// <summary>
/// Overall metrics associated with text after layout.
/// All coordinates are in device independent pixels (DIPs).
/// </summary>
typedef struct DWRITE_TEXT_METRICS {
	/// <summary>
	/// Left-most point of formatted text relative to layout box
	/// (excluding any glyph overhang).
	/// </summary>
	FLOAT left;

	/// <summary>
	/// Top-most point of formatted text relative to layout box
	/// (excluding any glyph overhang).
	/// </summary>
	FLOAT top;

	/// <summary>
	/// The width of the formatted text ignoring trailing whitespace
	/// at the end of each line.
	/// </summary>
	FLOAT width;

	/// <summary>
	/// The width of the formatted text taking into account the
	/// trailing whitespace at the end of each line.
	/// </summary>
	FLOAT widthIncludingTrailingWhitespace;

	/// <summary>
	/// The height of the formatted text. The height of an empty string
	/// is determined by the size of the default font's line height.
	/// </summary>
	FLOAT height;

	/// <summary>
	/// Initial width given to the layout. Depending on whether the text
	/// was wrapped or not, it can be either larger or smaller than the
	/// text content width.
	/// </summary>
	FLOAT layoutWidth;

	/// <summary>
	/// Initial height given to the layout. Depending on the length of the
	/// text, it may be larger or smaller than the text content height.
	/// </summary>
	FLOAT layoutHeight;

	/// <summary>
	/// The maximum reordering count of any line of text, used
	/// to calculate the most number of hit-testing boxes needed.
	/// If the layout has no bidirectional text or no text at all,
	/// the minimum level is 1.
	/// </summary>
	UINT32 maxBidiReorderingDepth;

	/// <summary>
	/// Total number of lines.
	/// </summary>
	UINT32 lineCount;
} DWRITE_TEXT_METRICS;


/// <summary>
/// Properties describing the geometric measurement of an
/// application-defined inline object.
/// </summary>
typedef struct DWRITE_INLINE_OBJECT_METRICS {
	/// <summary>
	/// Width of the inline object.
	/// </summary>
	FLOAT width;

	/// <summary>
	/// Height of the inline object as measured from top to bottom.
	/// </summary>
	FLOAT height;

	/// <summary>
	/// Distance from the top of the object to the baseline where it is lined up with the adjacent text.
	/// If the baseline is at the bottom, baseline simply equals height.
	/// </summary>
	FLOAT baseline;

	/// <summary>
	/// Flag indicating whether the object is to be placed upright or alongside the text baseline
	/// for vertical text.
	/// </summary>
	BOOL  supportsSideways;
} DWRITE_INLINE_OBJECT_METRICS;


/// <summary>
/// The DWRITE_OVERHANG_METRICS structure holds how much any visible pixels
/// (in DIPs) overshoot each side of the layout or inline objects.
/// </summary>
/// <remarks>
/// Positive overhangs indicate that the visible area extends outside the layout
/// box or inline object, while negative values mean there is whitespace inside.
/// The returned values are unaffected by rendering transforms or pixel snapping.
/// Additionally, they may not exactly match final target's pixel bounds after
/// applying grid fitting and hinting.
/// </remarks>
typedef struct DWRITE_OVERHANG_METRICS {
	/// <summary>
	/// The distance from the left-most visible DIP to its left alignment edge.
	/// </summary>
	FLOAT left;

	/// <summary>
	/// The distance from the top-most visible DIP to its top alignment edge.
	/// </summary>
	FLOAT top;

	/// <summary>
	/// The distance from the right-most visible DIP to its right alignment edge.
	/// </summary>
	FLOAT right;

	/// <summary>
	/// The distance from the bottom-most visible DIP to its bottom alignment edge.
	/// </summary>
	FLOAT bottom;
} DWRITE_OVERHANG_METRICS;


/// <summary>
/// Geometry enclosing of text positions.
/// </summary>
typedef struct DWRITE_HIT_TEST_METRICS {
	/// <summary>
	/// First text position within the geometry.
	/// </summary>
	UINT32 textPosition;

	/// <summary>
	/// Number of text positions within the geometry.
	/// </summary>
	UINT32 length;

	/// <summary>
	/// Left position of the top-left coordinate of the geometry.
	/// </summary>
	FLOAT left;

	/// <summary>
	/// Top position of the top-left coordinate of the geometry.
	/// </summary>
	FLOAT top;

	/// <summary>
	/// Geometry's width.
	/// </summary>
	FLOAT width;

	/// <summary>
	/// Geometry's height.
	/// </summary>
	FLOAT height;

	/// <summary>
	/// Bidi level of text positions enclosed within the geometry.
	/// </summary>
	UINT32 bidiLevel;

	/// <summary>
	/// Geometry encloses text?
	/// </summary>
	BOOL isText;

	/// <summary>
	/// Range is trimmed.
	/// </summary>
	BOOL isTrimmed;
} DWRITE_HIT_TEST_METRICS;


struct IDWriteInlineObjectVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteInlineObject* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteInlineObject* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteInlineObject* This);

	STDMETHOD(Draw)(
		IDWriteInlineObject* This,
		_In_opt_ void* clientDrawingContext,
		_In_ IDWriteTextRenderer* renderer,
		FLOAT originX,
		FLOAT originY,
		BOOL isSideways,
		BOOL isRightToLeft,
		_In_opt_ IUnknown* clientDrawingEffect
		) PURE;

	STDMETHOD(GetMetrics)(
		IDWriteInlineObject* This,
		_Out_ DWRITE_INLINE_OBJECT_METRICS* metrics
		) PURE;

	STDMETHOD(GetOverhangMetrics)(
		IDWriteInlineObject* This,
		_Out_ DWRITE_OVERHANG_METRICS* overhangs
		) PURE;

	STDMETHOD(GetBreakConditions)(
		IDWriteInlineObject* This,
		_Out_ DWRITE_BREAK_CONDITION* breakConditionBefore,
		_Out_ DWRITE_BREAK_CONDITION* breakConditionAfter
		) PURE;
};

interface IDWriteInlineObject {
	struct IDWriteInlineObjectVtbl* lpVtbl;
};


#define IDWriteInlineObject_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteInlineObject_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteInlineObject_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteInlineObject_Draw(This,clientDrawingContext,renderer,originX,originY,isSideways,isRightToLeft,clientDrawingEffect) \
	((This)->lpVtbl->Draw(This,clientDrawingContext,renderer,originX,originY,isSideways,isRightToLeft,clientDrawingEffect))

#define IDWriteInlineObject_GetMetrics(This,metrics) \
	((This)->lpVtbl->GetMetrics(This,metrics))

#define IDWriteInlineObject_GetOverhangMetrics(This,overhangs) \
	((This)->lpVtbl->GetOverhangMetrics(This,overhangs))

#define IDWriteInlineObject_GetBreakConditions(This,breakConditionBefore,breakConditionAfter) \
	((This)->lpVtbl->GetBreakConditions(This,breakConditionBefore,breakConditionAfter))


struct IDWritePixelSnappingVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWritePixelSnapping* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWritePixelSnapping* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWritePixelSnapping* This);

	STDMETHOD(IsPixelSnappingDisabled)(
		IDWritePixelSnapping* This,
		_In_opt_ void* clientDrawingContext,
		_Out_ BOOL* isDisabled
		) PURE;

	STDMETHOD(GetCurrentTransform)(
		IDWritePixelSnapping* This,
		_In_opt_ void* clientDrawingContext,
		_Out_ DWRITE_MATRIX* transform
		) PURE;

	STDMETHOD(GetPixelsPerDip)(
		IDWritePixelSnapping* This,
		_In_opt_ void* clientDrawingContext,
		_Out_ FLOAT* pixelsPerDip
		) PURE;
};

interface IDWritePixelSnapping {
	struct IDWritePixelSnappingVtbl* lpVtbl;
};

#define IDWritePixelSnapping_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWritePixelSnapping_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWritePixelSnapping_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWritePixelSnapping_IsPixelSnappingDisabled(This,clientDrawingContext,isDisabled) \
	((This)->lpVtbl->IsPixelSnappingDisabled(This,clientDrawingContext,isDisabled))

#define IDWritePixelSnapping_GetCurrentTransform(This,clientDrawingContext,transform) \
	((This)->lpVtbl->GetCurrentTransform(This,clientDrawingContext,transform))

#define IDWritePixelSnapping_GetPixelsPerDip(This,clientDrawingContext,pixelsPerDip) \
	((This)->lpVtbl->GetPixelsPerDip(This,clientDrawingContext,pixelsPerDip))


struct IDWriteTextRendererVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteTextRenderer* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteTextRenderer* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteTextRenderer* This);

	STDMETHOD(IsPixelSnappingDisabled)(
		IDWriteTextRenderer* This,
		_In_opt_ void* clientDrawingContext,
		_Out_ BOOL* isDisabled
		) PURE;

	STDMETHOD(GetCurrentTransform)(
		IDWriteTextRenderer* This,
		_In_opt_ void* clientDrawingContext,
		_Out_ DWRITE_MATRIX* transform
		) PURE;

	STDMETHOD(GetPixelsPerDip)(
		IDWriteTextRenderer* This,
		_In_opt_ void* clientDrawingContext,
		_Out_ FLOAT* pixelsPerDip
		) PURE;

	STDMETHOD(DrawGlyphRun)(
		IDWriteTextRenderer* This,
		_In_opt_ void* clientDrawingContext,
		FLOAT baselineOriginX,
		FLOAT baselineOriginY,
		DWRITE_MEASURING_MODE measuringMode,
		_In_ DWRITE_GLYPH_RUN const* glyphRun,
		_In_ DWRITE_GLYPH_RUN_DESCRIPTION const* glyphRunDescription,
		_In_opt_ IUnknown* clientDrawingEffect
		) PURE;

	STDMETHOD(DrawUnderline)(
		IDWriteTextRenderer* This,
		_In_opt_ void* clientDrawingContext,
		FLOAT baselineOriginX,
		FLOAT baselineOriginY,
		_In_ DWRITE_UNDERLINE const* underline,
		_In_opt_ IUnknown* clientDrawingEffect
		) PURE;

	STDMETHOD(DrawStrikethrough)(
		IDWriteTextRenderer* This,
		_In_opt_ void* clientDrawingContext,
		FLOAT baselineOriginX,
		FLOAT baselineOriginY,
		_In_ DWRITE_STRIKETHROUGH const* strikethrough,
		_In_opt_ IUnknown* clientDrawingEffect
		) PURE;

	STDMETHOD(DrawInlineObject)(
		IDWriteTextRenderer* This,
		_In_opt_ void* clientDrawingContext,
		FLOAT originX,
		FLOAT originY,
		_In_ IDWriteInlineObject* inlineObject,
		BOOL isSideways,
		BOOL isRightToLeft,
		_In_opt_ IUnknown* clientDrawingEffect
		) PURE;
};

interface IDWriteTextRenderer {
	struct IDWriteTextRendererVtbl* lpVtbl;
};

#define IDWriteTextRenderer_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteTextRenderer_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteTextRenderer_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteTextRenderer_IsPixelSnappingDisabled(This,clientDrawingContext,isDisabled) \
	((This)->lpVtbl->IsPixelSnappingDisabled(This,clientDrawingContext,isDisabled))

#define IDWriteTextRenderer_GetCurrentTransform(This,clientDrawingContext,transform) \
	((This)->lpVtbl->GetCurrentTransform(This,clientDrawingContext,transform))

#define IDWriteTextRenderer_GetPixelsPerDip(This,clientDrawingContext,pixelsPerDip) \
	((This)->lpVtbl->GetPixelsPerDip(This,clientDrawingContext,pixelsPerDip))

#define IDWriteTextRenderer_DrawGlyphRun(This,clientDrawingContext,baselineOriginX,baselineOriginY,measuringMode,glyphRun,glyphRunDescription,clientDrawingEffect) \
	((This)->lpVtbl->DrawGlyphRun(This,clientDrawingContext,baselineOriginX,baselineOriginY,measuringMode,glyphRun,glyphRunDescription,clientDrawingEffect))

#define IDWriteTextRenderer_DrawUnderline(This,clientDrawingContext,baselineOriginX,baselineOriginY,underline,clientDrawingEffect) \
	((This)->lpVtbl->DrawUnderline(This,clientDrawingContext,baselineOriginX,baselineOriginY,underline,clientDrawingEffect))

#define IDWriteTextRenderer_DrawStrikethrough(This,clientDrawingContext,baselineOriginX,baselineOriginY,strikethrough,clientDrawingEffect) \
	((This)->lpVtbl->DrawStrikethrough(This,clientDrawingContext,baselineOriginX,baselineOriginY,strikethrough,clientDrawingEffect))

#define IDWriteTextRenderer_DrawInlineObject(This,clientDrawingContext,originX,originY,inlineObject,isSideways,isRightToLeft,clientDrawingEffect) \
	((This)->lpVtbl->DrawInlineObject(This,clientDrawingContext,originX,originY,inlineObject,isSideways,isRightToLeft,clientDrawingEffect))


struct IDWriteTextLayoutVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteTextLayout* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteTextLayout* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteTextLayout* This);

	STDMETHOD(SetTextAlignment)(
		IDWriteTextLayout* This,
		DWRITE_TEXT_ALIGNMENT textAlignment
		) PURE;

	STDMETHOD(SetParagraphAlignment)(
		IDWriteTextLayout* This,
		DWRITE_PARAGRAPH_ALIGNMENT paragraphAlignment
		) PURE;

	STDMETHOD(SetWordWrapping)(
		IDWriteTextLayout* This,
		DWRITE_WORD_WRAPPING wordWrapping
		) PURE;

	STDMETHOD(SetReadingDirection)(
		IDWriteTextLayout* This,
		DWRITE_READING_DIRECTION readingDirection
		) PURE;

	STDMETHOD(SetFlowDirection)(
		IDWriteTextLayout* This,
		DWRITE_FLOW_DIRECTION flowDirection
		) PURE;

	STDMETHOD(SetIncrementalTabStop)(
		IDWriteTextLayout* This,
		FLOAT incrementalTabStop
		) PURE;

	STDMETHOD(SetTrimming)(
		IDWriteTextLayout* This,
		_In_ DWRITE_TRIMMING const* trimmingOptions,
		_In_opt_ IDWriteInlineObject* trimmingSign
		) PURE;

	STDMETHOD(SetLineSpacing)(
		IDWriteTextLayout* This,
		DWRITE_LINE_SPACING_METHOD lineSpacingMethod,
		FLOAT lineSpacing,
		FLOAT baseline
		) PURE;

	STDMETHOD_(DWRITE_TEXT_ALIGNMENT, GetTextAlignment)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD_(DWRITE_PARAGRAPH_ALIGNMENT, GetParagraphAlignment)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD_(DWRITE_WORD_WRAPPING, GetWordWrapping)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD_(DWRITE_READING_DIRECTION, GetReadingDirection)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD_(DWRITE_FLOW_DIRECTION, GetFlowDirection)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD_(FLOAT, GetIncrementalTabStop)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD(GetTrimming)(
		IDWriteTextLayout* This,
		_Out_ DWRITE_TRIMMING* trimmingOptions,
		_COM_Outptr_ IDWriteInlineObject** trimmingSign
		) PURE;

	STDMETHOD(GetLineSpacing)(
		IDWriteTextLayout* This,
		_Out_ DWRITE_LINE_SPACING_METHOD* lineSpacingMethod,
		_Out_ FLOAT* lineSpacing,
		_Out_ FLOAT* baseline
		) PURE;

	STDMETHOD(SetMaxWidth)(
		IDWriteTextLayout* This,
		FLOAT maxWidth
		) PURE;

	STDMETHOD(SetMaxHeight)(
		IDWriteTextLayout* This,
		FLOAT maxHeight
		) PURE;

	STDMETHOD(SetFontCollection)(
		IDWriteTextLayout* This,
		_In_ IDWriteFontCollection* fontCollection,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetFontFamilyName)(
		IDWriteTextLayout* This,
		_In_z_ WCHAR const* fontFamilyName,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetFontWeight)(
		IDWriteTextLayout* This,
		DWRITE_FONT_WEIGHT fontWeight,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetFontStyle)(
		IDWriteTextLayout* This,
		DWRITE_FONT_STYLE fontStyle,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetFontStretch)(
		IDWriteTextLayout* This,
		DWRITE_FONT_STRETCH fontStretch,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetFontSize)(
		IDWriteTextLayout* This,
		FLOAT fontSize,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetUnderline)(
		IDWriteTextLayout* This,
		BOOL hasUnderline,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetStrikethrough)(
		IDWriteTextLayout* This,
		BOOL hasStrikethrough,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetDrawingEffect)(
		IDWriteTextLayout* This,
		IUnknown* drawingEffect,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetInlineObject)(
		IDWriteTextLayout* This,
		_In_ IDWriteInlineObject* inlineObject,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetTypography)(
		IDWriteTextLayout* This,
		_In_ IDWriteTypography* typography,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD(SetLocaleName)(
		IDWriteTextLayout* This,
		_In_z_ WCHAR const* localeName,
		DWRITE_TEXT_RANGE textRange
		) PURE;

	STDMETHOD_(FLOAT, GetMaxWidth)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD_(FLOAT, GetMaxHeight)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD(GetFontCollection)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_COM_Outptr_ IDWriteFontCollection** fontCollection,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetFontFamilyNameLength)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_Out_ UINT32* nameLength,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetFontFamilyName)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_Out_writes_z_(nameSize) WCHAR* fontFamilyName,
		UINT32 nameSize,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetFontWeight)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_Out_ DWRITE_FONT_WEIGHT* fontWeight,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetFontStyle)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_Out_ DWRITE_FONT_STYLE* fontStyle,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetFontStretch)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_Out_ DWRITE_FONT_STRETCH* fontStretch,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetFontSize)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_Out_ FLOAT* fontSize,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetUnderline)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_Out_ BOOL* hasUnderline,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetStrikethrough)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_Out_ BOOL* hasStrikethrough,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetDrawingEffect)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_COM_Outptr_ IUnknown** drawingEffect,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetInlineObject)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_COM_Outptr_ IDWriteInlineObject** inlineObject,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetTypography)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_COM_Outptr_ IDWriteTypography** typography,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetLocaleNameLength)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_Out_ UINT32* nameLength,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(GetLocaleName)(
		IDWriteTextLayout* This,
		UINT32 currentPosition,
		_Out_writes_z_(nameSize) WCHAR* localeName,
		UINT32 nameSize,
		_Out_opt_ DWRITE_TEXT_RANGE* textRange
		) PURE;

	STDMETHOD(Draw)(
		IDWriteTextLayout* This,
		_In_opt_ void* clientDrawingContext,
		_In_ IDWriteTextRenderer* renderer,
		FLOAT originX,
		FLOAT originY
		) PURE;

	STDMETHOD(GetLineMetrics)(
		IDWriteTextLayout* This,
		_Out_writes_opt_(maxLineCount) DWRITE_LINE_METRICS* lineMetrics,
		UINT32 maxLineCount,
		_Out_ UINT32* actualLineCount
		) PURE;

	STDMETHOD(GetMetrics)(
		IDWriteTextLayout* This,
		_Out_ DWRITE_TEXT_METRICS* textMetrics
		) PURE;

	STDMETHOD(GetOverhangMetrics)(
		IDWriteTextLayout* This,
		_Out_ DWRITE_OVERHANG_METRICS* overhangs
		) PURE;

	STDMETHOD(GetClusterMetrics)(
		IDWriteTextLayout* This,
		_Out_writes_opt_(maxClusterCount) DWRITE_CLUSTER_METRICS* clusterMetrics,
		UINT32 maxClusterCount,
		_Out_ UINT32* actualClusterCount
		) PURE;

	STDMETHOD(DetermineMinWidth)(
		IDWriteTextLayout* This,
		_Out_ FLOAT* minWidth
		) PURE;

	STDMETHOD(HitTestPoint)(
		IDWriteTextLayout* This,
		FLOAT pointX,
		FLOAT pointY,
		_Out_ BOOL* isTrailingHit,
		_Out_ BOOL* isInside,
		_Out_ DWRITE_HIT_TEST_METRICS* hitTestMetrics
		) PURE;

	STDMETHOD(HitTestTextPosition)(
		IDWriteTextLayout* This,
		UINT32 textPosition,
		BOOL isTrailingHit,
		_Out_ FLOAT* pointX,
		_Out_ FLOAT* pointY,
		_Out_ DWRITE_HIT_TEST_METRICS* hitTestMetrics
		) PURE;

	STDMETHOD(HitTestTextRange)(
		IDWriteTextLayout* This,
		UINT32 textPosition,
		UINT32 textLength,
		FLOAT originX,
		FLOAT originY,
		_Out_writes_opt_(maxHitTestMetricsCount) DWRITE_HIT_TEST_METRICS* hitTestMetrics,
		UINT32 maxHitTestMetricsCount,
		_Out_ UINT32* actualHitTestMetricsCount
		) PURE;

	STDMETHOD(GetFontCollection2)(
		IDWriteTextLayout* This,
		_COM_Outptr_ IDWriteFontCollection** fontCollection
		) PURE;

	STDMETHOD_(UINT32, GetFontFamilyNameLength2)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD(GetFontFamilyName2)(
		IDWriteTextLayout* This,
		_Out_writes_z_(nameSize) WCHAR* fontFamilyName,
		UINT32 nameSize
		) PURE;

	STDMETHOD_(DWRITE_FONT_WEIGHT, GetFontWeight2)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD_(DWRITE_FONT_STYLE, GetFontStyle2)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD_(DWRITE_FONT_STRETCH, GetFontStretch2)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD_(FLOAT, GetFontSize2)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD_(UINT32, GetLocaleNameLength2)(
		IDWriteTextLayout* This) PURE;

	STDMETHOD(GetLocaleName2)(
		IDWriteTextLayout* This,
		_Out_writes_z_(nameSize) WCHAR* localeName,
		UINT32 nameSize
		) PURE;
};

interface IDWriteTextLayout {
	struct IDWriteTextLayoutVtbl* lpVtbl;
};

#define IDWriteTextLayout_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteTextLayout_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteTextLayout_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteTextLayout_SetTextAlignment(This,textAlignment) \
	((This)->lpVtbl->SetTextAlignment(This,textAlignment))

#define IDWriteTextLayout_SetParagraphAlignment(This,paragraphAlignment) \
	((This)->lpVtbl->SetParagraphAlignment(This,paragraphAlignment))

#define IDWriteTextLayout_SetWordWrapping(This,wordWrapping) \
	((This)->lpVtbl->SetWordWrapping(This,wordWrapping))

#define IDWriteTextLayout_SetReadingDirection(This,readingDirection) \
	((This)->lpVtbl->SetReadingDirection(This,readingDirection))

#define IDWriteTextLayout_SetFlowDirection(This,flowDirection) \
	((This)->lpVtbl->SetFlowDirection(This,flowDirection))

#define IDWriteTextLayout_SetIncrementalTabStop(This,incrementalTabStop) \
	((This)->lpVtbl->SetIncrementalTabStop(This,incrementalTabStop))

#define IDWriteTextLayout_SetTrimming(This,trimmingSign,trimmingSignCount) \
	((This)->lpVtbl->SetTrimming(This,trimmingSign,trimmingSignCount))

#define IDWriteTextLayout_SetLineSpacing(This,lineSpacingMethod,lineSpacing,baseline) \
	((This)->lpVtbl->SetLineSpacing(This,lineSpacingMethod,lineSpacing,baseline))

#define IDWriteTextLayout_GetTextAlignment(This) \
	((This)->lpVtbl->GetTextAlignment(This))

#define IDWriteTextLayout_GetParagraphAlignment(This) \
	((This)->lpVtbl->GetParagraphAlignment(This))

#define IDWriteTextLayout_GetWordWrapping(This) \
	((This)->lpVtbl->GetWordWrapping(This))

#define IDWriteTextLayout_GetReadingDirection(This) \
	((This)->lpVtbl->GetReadingDirection(This))

#define IDWriteTextLayout_GetFlowDirection(This) \
	((This)->lpVtbl->GetFlowDirection(This))

#define IDWriteTextLayout_GetIncrementalTabStop(This) \
	((This)->lpVtbl->GetIncrementalTabStop(This))

#define IDWriteTextLayout_GetTrimming(This,trimmingSign,trimmingSignCount) \
	((This)->lpVtbl->GetTrimming(This,trimmingSign,trimmingSignCount))

#define IDWriteTextLayout_GetLineSpacing(This,lineSpacingMethod,lineSpacing,baseline) \
	((This)->lpVtbl->GetLineSpacing(This,lineSpacingMethod,lineSpacing,baseline))

#define IDWriteTextLayout_SetMaxWidth(This,maxWidth) \
	((This)->lpVtbl->SetMaxWidth(This,maxWidth))

#define IDWriteTextLayout_SetMaxHeight(This,maxHeight) \
	((This)->lpVtbl->SetMaxHeight(This,maxHeight))

#define IDWriteTextLayout_SetFontCollection(This,fontCollection,textRange) \
	((This)->lpVtbl->SetFontCollection(This,fontCollection,textRange))

#define IDWriteTextLayout_SetFontFamilyName(This,fontFamilyName,textRange) \
	((This)->lpVtbl->SetFontFamilyName(This,fontFamilyName,textRange))

#define IDWriteTextLayout_SetFontWeight(This,fontWeight,textRange) \
	((This)->lpVtbl->SetFontWeight(This,fontWeight,textRange))

#define IDWriteTextLayout_SetFontStyle(This,fontStyle,textRange) \
	((This)->lpVtbl->SetFontStyle(This,fontStyle,textRange))

#define IDWriteTextLayout_SetFontStretch(This,fontStretch,textRange) \
	((This)->lpVtbl->SetFontStretch(This,fontStretch,textRange))

#define IDWriteTextLayout_SetFontSize(This,fontSize,textRange) \
	((This)->lpVtbl->SetFontSize(This,fontSize,textRange))

#define IDWriteTextLayout_SetUnderline(This,hasUnderline,textRange) \
	((This)->lpVtbl->SetUnderline(This,hasUnderline,textRange))

#define IDWriteTextLayout_SetStrikethrough(This,hasStrikethrough,textRange) \
	((This)->lpVtbl->SetStrikethrough(This,hasStrikethrough,textRange))

#define IDWriteTextLayout_SetDrawingEffect(This,drawingEffect,textRange) \
	((This)->lpVtbl->SetDrawingEffect(This,drawingEffect,textRange))

#define IDWriteTextLayout_SetInlineObject(This,inlineObject,textRange) \
	((This)->lpVtbl->SetInlineObject(This,inlineObject,textRange))

#define IDWriteTextLayout_SetTypography(This,typography,textRange) \
	((This)->lpVtbl->SetTypography(This,typography,textRange))

#define IDWriteTextLayout_SetLocaleName(This,localeName,textRange) \
	((This)->lpVtbl->SetLocaleName(This,localeName,textRange))

#define IDWriteTextLayout_GetMaxWidth(This) \
	((This)->lpVtbl->GetMaxWidth(This))

#define IDWriteTextLayout_GetMaxHeight(This) \
	((This)->lpVtbl->GetMaxHeight(This))

#define IDWriteTextLayout_GetFontCollection(This,currentPosition,textRange,fontCollection) \
	((This)->lpVtbl->GetFontCollection(This,currentPosition,textRange,fontCollection))

#define IDWriteTextLayout_GetFontFamilyNameLength(This,currentPosition,textRange) \
	((This)->lpVtbl->GetFontFamilyNameLength(This,currentPosition,textRange))

#define IDWriteTextLayout_GetFontFamilyName(This,currentPosition,textRange,fontFamilyName,nameSize) \
	((This)->lpVtbl->GetFontFamilyName(This,currentPosition,textRange,fontFamilyName,nameSize))

#define IDWriteTextLayout_GetFontWeight(This,currentPosition,textRange,fontWeight) \
	((This)->lpVtbl->GetFontWeight(This,currentPosition,textRange,fontWeight))

#define IDWriteTextLayout_GetFontStyle(This,currentPosition,textRange,fontStyle) \
	((This)->lpVtbl->GetFontStyle(This,currentPosition,textRange,fontStyle))

#define IDWriteTextLayout_GetFontStretch(This,currentPosition,textRange,fontStretch) \
	((This)->lpVtbl->GetFontStretch(This,currentPosition,textRange,fontStretch))

#define IDWriteTextLayout_GetFontSize(This,currentPosition,textRange,fontSize) \
	((This)->lpVtbl->GetFontSize(This,currentPosition,textRange,fontSize))

#define IDWriteTextLayout_GetUnderline(This,currentPosition,textRange,hasUnderline) \
	((This)->lpVtbl->GetUnderline(This,currentPosition,textRange,hasUnderline))

#define IDWriteTextLayout_GetStrikethrough(This,currentPosition,textRange,hasStrikethrough) \
	((This)->lpVtbl->GetStrikethrough(This,currentPosition,textRange,hasStrikethrough))

#define IDWriteTextLayout_GetDrawingEffect(This,currentPosition,textRange,drawingEffect) \
	((This)->lpVtbl->GetDrawingEffect(This,currentPosition,textRange,drawingEffect))

#define IDWriteTextLayout_GetInlineObject(This,currentPosition,textRange,inlineObject) \
	((This)->lpVtbl->GetInlineObject(This,currentPosition,textRange,inlineObject))

#define IDWriteTextLayout_GetTypography(This,currentPosition,textRange,typography) \
	((This)->lpVtbl->GetTypography(This,currentPosition,textRange,typography))

#define IDWriteTextLayout_GetLocaleNameLength(This,currentPosition,textRange) \
	((This)->lpVtbl->GetLocaleNameLength(This,currentPosition,textRange))

#define IDWriteTextLayout_GetLocaleName(This,currentPosition,textRange,localeName,nameSize) \
	((This)->lpVtbl->GetLocaleName(This,currentPosition,textRange,localeName,nameSize))

#define IDWriteTextLayout_Draw(This,clientDrawingContext,renderer,originX,originY) \
	((This)->lpVtbl->Draw(This,clientDrawingContext,renderer,originX,originY))

#define IDWriteTextLayout_GetLineMetrics(This,lineMetrics,maxLineCount,actualLineCount) \
	((This)->lpVtbl->GetLineMetrics(This,lineMetrics,maxLineCount,actualLineCount))

#define IDWriteTextLayout_GetMetrics(This,textMetrics) \
	((This)->lpVtbl->GetMetrics(This,textMetrics))

#define IDWriteTextLayout_GetOverhangMetrics(This,overhangs) \
	((This)->lpVtbl->GetOverhangMetrics(This,overhangs))

#define IDWriteTextLayout_GetClusterMetrics(This,clusterMetrics,maxClusterCount,actualClusterCount) \
	((This)->lpVtbl->GetClusterMetrics(This,clusterMetrics,maxClusterCount,actualClusterCount))

#define IDWriteTextLayout_DetermineMinWidth(This) \
	((This)->lpVtbl->DetermineMinWidth(This))

#define IDWriteTextLayout_HitTestPoint(This,pointX,pointY,isTrailingHit,isInside,hitTestMetrics) \
	((This)->lpVtbl->HitTestPoint(This,pointX,pointY,isTrailingHit,isInside,hitTestMetrics))

#define IDWriteTextLayout_HitTestTextPosition(This,textPosition,isTrailingHit,isInside,hitTestMetrics) \
	((This)->lpVtbl->HitTestTextPosition(This,textPosition,isTrailingHit,isInside,hitTestMetrics))

#define IDWriteTextLayout_HitTestTextRange(This,textPosition,textLength,originX,originY,hitTestMetrics) \
	((This)->lpVtbl->HitTestTextRange(This,textPosition,textLength,originX,originY,hitTestMetrics))

#define IDWriteTextLayout_GetFontCollection2(This, fontCollection) \
	((This)->lpVtbl->GetFontCollection2(This, fontCollection))

#define IDWriteTextLayout_GetFontFamilyNameLength2(This) \
	((This)->lpVtbl->GetFontFamilyNameLength2(This))

#define IDWriteTextLayout_GetFontFamilyName2(This, fontFamilyName, nameSize) \
	((This)->lpVtbl->GetFontFamilyName2(This, fontFamilyName, nameSize))

#define IDWriteTextLayout_GetFontWeight2(This) \
	((This)->lpVtbl->GetFontWeight2(This))

#define IDWriteTextLayout_GetFontStyle2(This) \
	((This)->lpVtbl->GetFontStyle2(This))

#define IDWriteTextLayout_GetFontStretch2(This) \
	((This)->lpVtbl->GetFontStretch2(This))

#define IDWriteTextLayout_GetFontSize2(This) \
	((This)->lpVtbl->GetFontSize2(This))

#define IDWriteTextLayout_GetLocaleNameLength2(This) \
	((This)->lpVtbl->GetLocaleNameLength2(This))

#define IDWriteTextLayout_GetLocaleName2(This, localeName, nameSize) \
	((This)->lpVtbl->GetLocaleName2(This, localeName, nameSize))


struct IDWriteBitmapRenderTargetVtbl {
	HRESULT(STDMETHODCALLTYPE * QueryInterface)(
		IDWriteBitmapRenderTarget* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE * AddRef)(
		IDWriteBitmapRenderTarget* This);

	ULONG(STDMETHODCALLTYPE * Release)(
		IDWriteBitmapRenderTarget* This);

	STDMETHOD(DrawGlyphRun)(
		IDWriteBitmapRenderTarget* This,
		FLOAT baselineOriginX,
		FLOAT baselineOriginY,
		DWRITE_MEASURING_MODE measuringMode,
		_In_ DWRITE_GLYPH_RUN const* glyphRun,
		_In_ IDWriteRenderingParams * renderingParams,
		COLORREF textColor,
		_Out_opt_ RECT * blackBoxRect
		) PURE;
	STDMETHOD_(HDC, GetMemoryDC)(
		IDWriteBitmapRenderTarget* This) PURE;

	STDMETHOD_(FLOAT, GetPixelsPerDip)(
		IDWriteBitmapRenderTarget* This) PURE;

	STDMETHOD(SetPixelsPerDip)(
		IDWriteBitmapRenderTarget* This,
		FLOAT pixelsPerDip
		) PURE;

	STDMETHOD(GetCurrentTransform)(
		IDWriteBitmapRenderTarget* This,
		_Out_ DWRITE_MATRIX * transform
		) PURE;

	STDMETHOD(SetCurrentTransform)(
		IDWriteBitmapRenderTarget* This,
		_In_opt_ DWRITE_MATRIX const* transform
		) PURE;

	STDMETHOD(GetSize)(
		IDWriteBitmapRenderTarget* This,
		_Out_ SIZE * size
		) PURE;

	STDMETHOD(Resize)(
		IDWriteBitmapRenderTarget* This,
		UINT32 width,
		UINT32 height
		) PURE;
};

interface IDWriteBitmapRenderTarget {
	struct IDWriteBitmapRenderTargetVtbl *lpVtbl;
};

#define IDWriteBitmapRenderTarget_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteBitmapRenderTarget_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteBitmapRenderTarget_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteBitmapRenderTarget_DrawGlyphRun(This,baselineOriginX,baselineOriginY,measuringMode,glyphRun,renderingParams,textColor,blackBoxRect) \
	((This)->lpVtbl->DrawGlyphRun(This,baselineOriginX,baselineOriginY,measuringMode,glyphRun,renderingParams,textColor,blackBoxRect))

#define IDWriteBitmapRenderTarget_GetMemoryDC(This) \
	((This)->lpVtbl->GetMemoryDC(This))

#define IDWriteBitmapRenderTarget_GetPixelsPerDip(This) \
	((This)->lpVtbl->GetPixelsPerDip(This))

#define IDWriteBitmapRenderTarget_SetPixelsPerDip(This,pixelsPerDip) \
	((This)->lpVtbl->SetPixelsPerDip(This,pixelsPerDip))

#define IDWriteBitmapRenderTarget_GetCurrentTransform(This,transform) \
	((This)->lpVtbl->GetCurrentTransform(This,transform))

#define IDWriteBitmapRenderTarget_SetCurrentTransform(This,transform) \
	((This)->lpVtbl->SetCurrentTransform(This,transform))

#define IDWriteBitmapRenderTarget_GetSize(This,size) \
	((This)->lpVtbl->GetSize(This,size))

#define IDWriteBitmapRenderTarget_Resize(This,width,height) \
	((This)->lpVtbl->Resize(This,width,height))


struct IDWriteGdiInteropVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteGdiInterop* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteGdiInterop* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteGdiInterop* This);

	STDMETHOD(CreateFontFromLOGFONT)(
		IDWriteGdiInterop* This,
		_In_ LOGFONTW const* logFont,
		_COM_Outptr_ IDWriteFont** font
		) PURE;

	STDMETHOD(ConvertFontToLOGFONT)(
		IDWriteGdiInterop* This,
		_In_ IDWriteFont* font,
		_Out_ LOGFONTW* logFont,
		_Out_ BOOL* isSystemFont
		) PURE;

	STDMETHOD(ConvertFontFaceToLOGFONT)(
		IDWriteGdiInterop* This,
		_In_ IDWriteFontFace* font,
		_Out_ LOGFONTW* logFont
		) PURE;

	STDMETHOD(CreateFontFaceFromHdc)(
		IDWriteGdiInterop* This,
		HDC hdc,
		_COM_Outptr_ IDWriteFontFace** fontFace
		) PURE;

	STDMETHOD(CreateBitmapRenderTarget)(
		IDWriteGdiInterop* This,
		_In_opt_ HDC hdc,
		UINT32 width,
		UINT32 height,
		_COM_Outptr_ IDWriteBitmapRenderTarget * *renderTarget
		) PURE;
};

interface IDWriteGdiInterop {
	struct IDWriteGdiInteropVtbl *lpVtbl;
};

#define IDWriteGdiInterop_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteGdiInterop_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteGdiInterop_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteGdiInterop_CreateFontFromLOGFONT(This,logFont,font) \
	((This)->lpVtbl->CreateFontFromLOGFONT(This,logFont,font))

#define IDWriteGdiInterop_ConvertFontToLOGFONT(This,font,logFont,isSystemFont) \
	((This)->lpVtbl->ConvertFontToLOGFONT(This,font,logFont,isSystemFont))

#define IDWriteGdiInterop_ConvertFontFaceToLOGFONT(This,font,logFont) \
	((This)->lpVtbl->ConvertFontFaceToLOGFONT(This,font,logFont))

#define IDWriteGdiInterop_CreateFontFaceFromHdc(This,hdc,fontFace) \
	((This)->lpVtbl->CreateFontFaceFromHdc(This,hdc,fontFace))

#define IDWriteGdiInterop_CreateBitmapRenderTarget(This,hdc,width,height,renderTarget) \
	((This)->lpVtbl->CreateBitmapRenderTarget(This,hdc,width,height,renderTarget))

/// <summary>
/// The DWRITE_TEXTURE_TYPE enumeration identifies a type of alpha texture. An alpha texture is a bitmap of alpha values, each
/// representing the darkness (i.e., opacity) of a pixel or subpixel.
/// </summary>
typedef enum DWRITE_TEXTURE_TYPE {
	/// <summary>
	/// Specifies an alpha texture for aliased text rendering (i.e., bi-level, where each pixel is either fully opaque or fully transparent),
	/// with one byte per pixel.
	/// </summary>
	DWRITE_TEXTURE_ALIASED_1x1,

	/// <summary>
	/// Specifies an alpha texture for ClearType text rendering, with three bytes per pixel in the horizontal dimension and
	/// one byte per pixel in the vertical dimension.
	/// </summary>
	DWRITE_TEXTURE_CLEARTYPE_3x1
} DWRITE_TEXTURE_TYPE;

/// <summary>
/// Maximum alpha value in a texture returned by IDWriteGlyphRunAnalysis::CreateAlphaTexture.
/// </summary>
#define DWRITE_ALPHA_MAX 255


struct IDWriteGlyphRunAnalysisVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteGlyphRunAnalysis* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteGlyphRunAnalysis* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteGlyphRunAnalysis* This);

	STDMETHOD(GetAlphaTextureBounds)(
		IDWriteGlyphRunAnalysis* This,
		DWRITE_TEXTURE_TYPE textureType,
		_Out_ RECT* textureBounds
		) PURE;

	STDMETHOD(CreateAlphaTexture)(
		IDWriteGlyphRunAnalysis* This,
		DWRITE_TEXTURE_TYPE textureType,
		_In_ RECT const* textureBounds,
		_Out_writes_bytes_(bufferSize) BYTE* alphaValues,
		UINT32 bufferSize
		) PURE;

	STDMETHOD(GetAlphaBlendParams)(
		IDWriteGlyphRunAnalysis* This,
		_In_ IDWriteRenderingParams * renderingParams,
		_Out_ FLOAT * blendGamma,
		_Out_ FLOAT * blendEnhancedContrast,
		_Out_ FLOAT * blendClearTypeLevel
		) PURE;
};

interface IDWriteGlyphRunAnalysis {
	struct IDWriteGlyphRunAnalysisVtbl *lpVtbl;
};

#define IDWriteGlyphRunAnalysis_QueryInterface(This,riid,ppvObject) \
	((This)->lpVtbl->QueryInterface(This,riid,ppvObject))

#define IDWriteGlyphRunAnalysis_AddRef(This) \
	((This)->lpVtbl->AddRef(This))

#define IDWriteGlyphRunAnalysis_Release(This) \
	((This)->lpVtbl->Release(This))

#define IDWriteGlyphRunAnalysis_GetAlphaTextureBounds(This,textureType,textureBounds) \
	((This)->lpVtbl->GetAlphaTextureBounds(This,textureType,textureBounds))

#define IDWriteGlyphRunAnalysis_CreateAlphaTexture(This,textureType,textureBounds,alphaValues,bufferSize) \
	((This)->lpVtbl->CreateAlphaTexture(This,textureType,textureBounds,alphaValues,bufferSize))

#define IDWriteGlyphRunAnalysis_GetAlphaBlendParams(This,renderingParams,blendGamma,blendEnhancedContrast,blendClearTypeLevel) \
	((This)->lpVtbl->GetAlphaBlendParams(This,renderingParams,blendGamma,blendEnhancedContrast,blendClearTypeLevel))


struct IDWriteFactoryVtbl {
	HRESULT(STDMETHODCALLTYPE* QueryInterface)(
		IDWriteFactory* This,
		/* [in] */ REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDWriteFactory* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDWriteFactory* This);

	STDMETHOD(GetSystemFontCollection)(
		IDWriteFactory* This,
		_COM_Outptr_ IDWriteFontCollection** fontCollection,
		BOOL checkForUpdates
		) PURE;

	STDMETHOD(CreateCustomFontCollection)(
		IDWriteFactory* This,
		_In_ IDWriteFontCollectionLoader* collectionLoader,
		_In_reads_bytes_(collectionKeySize) void const* collectionKey,
		UINT32 collectionKeySize,
		_COM_Outptr_ IDWriteFontCollection** fontCollection
		) PURE;

	STDMETHOD(RegisterFontCollectionLoader)(
		IDWriteFactory* This,
		_In_ IDWriteFontCollectionLoader* fontCollectionLoader
		) PURE;

	STDMETHOD(UnregisterFontCollectionLoader)(
		IDWriteFactory* This,
		_In_ IDWriteFontCollectionLoader* fontCollectionLoader
		) PURE;

	STDMETHOD(CreateFontFileReference)(
		IDWriteFactory* This,
		_In_z_ WCHAR const* filePath,
		_In_opt_ FILETIME const* lastWriteTime,
		_COM_Outptr_ IDWriteFontFile** fontFile
		) PURE;

	STDMETHOD(CreateCustomFontFileReference)(
		IDWriteFactory* This,
		_In_reads_bytes_(fontFileReferenceKeySize) void const* fontFileReferenceKey,
		UINT32 fontFileReferenceKeySize,
		_In_ IDWriteFontFileLoader* fontFileLoader,
		_COM_Outptr_ IDWriteFontFile** fontFile
		) PURE;

	STDMETHOD(CreateFontFace)(
		IDWriteFactory* This,
		DWRITE_FONT_FACE_TYPE fontFaceType,
		UINT32 numberOfFiles,
		_In_reads_(numberOfFiles) IDWriteFontFile* const* fontFiles,
		UINT32 faceIndex,
		DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags,
		_COM_Outptr_ IDWriteFontFace** fontFace
		) PURE;

	STDMETHOD(CreateRenderingParams)(
		IDWriteFactory* This,
		_COM_Outptr_ IDWriteRenderingParams** renderingParams
		) PURE;

	STDMETHOD(CreateMonitorRenderingParams)(
		IDWriteFactory* This,
		HMONITOR monitor,
		_COM_Outptr_ IDWriteRenderingParams** renderingParams
		) PURE;

	STDMETHOD(CreateCustomRenderingParams)(
		IDWriteFactory* This,
		FLOAT gamma,
		FLOAT enhancedContrast,
		FLOAT clearTypeLevel,
		DWRITE_PIXEL_GEOMETRY pixelGeometry,
		DWRITE_RENDERING_MODE renderingMode,
		_COM_Outptr_ IDWriteRenderingParams** renderingParams
		) PURE;

	STDMETHOD(RegisterFontFileLoader)(
		IDWriteFactory* This,
		_In_ IDWriteFontFileLoader* fontFileLoader
		) PURE;

	STDMETHOD(UnregisterFontFileLoader)(
		IDWriteFactory* This,
		_In_ IDWriteFontFileLoader* fontFileLoader
		) PURE;

	STDMETHOD(CreateTextFormat)(
		IDWriteFactory* This,
		_In_z_ WCHAR const* fontFamilyName,
		_In_opt_ IDWriteFontCollection* fontCollection,
		DWRITE_FONT_WEIGHT fontWeight,
		DWRITE_FONT_STYLE fontStyle,
		DWRITE_FONT_STRETCH fontStretch,
		FLOAT fontSize,
		_In_z_ WCHAR const* localeName,
		_COM_Outptr_ IDWriteTextFormat** textFormat
		) PURE;

	STDMETHOD(CreateTypography)(
		IDWriteFactory* This,
		_COM_Outptr_ IDWriteTypography** typography
		) PURE;

	STDMETHOD(GetGdiInterop)(
		IDWriteFactory* This,
		_COM_Outptr_ IDWriteGdiInterop** gdiInterop
		) PURE;

	STDMETHOD(CreateTextLayout)(
		IDWriteFactory* This,
		_In_reads_(stringLength) WCHAR const* string,
		UINT32 stringLength,
		_In_ IDWriteTextFormat* textFormat,
		FLOAT maxWidth,
		FLOAT maxHeight,
		_COM_Outptr_ IDWriteTextLayout** textLayout
		) PURE;

	STDMETHOD(CreateGdiCompatibleTextLayout)(
		IDWriteFactory* This,
		_In_reads_(stringLength) WCHAR const* string,
		UINT32 stringLength,
		_In_ IDWriteTextFormat* textFormat,
		FLOAT layoutWidth,
		FLOAT layoutHeight,
		FLOAT pixelsPerDip,
		_In_opt_ DWRITE_MATRIX const* transform,
		BOOL useGdiNatural,
		_COM_Outptr_ IDWriteTextLayout** textLayout
		) PURE;

	STDMETHOD(CreateEllipsisTrimmingSign)(
		IDWriteFactory* This,
		_In_ IDWriteTextFormat* textFormat,
		_COM_Outptr_ IDWriteInlineObject** trimmingSign
		) PURE;

	STDMETHOD(CreateTextAnalyzer)(
		IDWriteFactory* This,
		_COM_Outptr_ IDWriteTextAnalyzer** textAnalyzer
		) PURE;

	STDMETHOD(CreateNumberSubstitution)(
		IDWriteFactory* This,
		_In_ DWRITE_NUMBER_SUBSTITUTION_METHOD substitutionMethod,
		_In_z_ WCHAR const* localeName,
		_In_ BOOL ignoreUserOverride,
		_COM_Outptr_ IDWriteNumberSubstitution** numberSubstitution
		) PURE;

	STDMETHOD(CreateGlyphRunAnalysis)(
		IDWriteFactory* This,
		_In_ DWRITE_GLYPH_RUN const* glyphRun,
		FLOAT pixelsPerDip,
		_In_opt_ DWRITE_MATRIX const* transform,
		DWRITE_RENDERING_MODE renderingMode,
		DWRITE_MEASURING_MODE measuringMode,
		FLOAT baselineOriginX,
		FLOAT baselineOriginY,
		_COM_Outptr_ IDWriteGlyphRunAnalysis * *glyphRunAnalysis
		) PURE;

}; // interface IDWriteFactory

interface IDWriteFactory {
	struct IDWriteFactoryVtbl* lpVtbl;
};

#define IDWriteFactory_QueryInterface(This,riid,ppvObject)	\
	( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )

#define IDWriteFactory_AddRef(This)	\
	( (This)->lpVtbl -> AddRef(This) )

#define IDWriteFactory_Release(This)	\
	( (This)->lpVtbl -> Release(This) )

#define IDWriteFactory_GetSystemFontCollection(This,checkForUpdates,fontCollection)	\
	( (This)->lpVtbl -> GetSystemFontCollection(This,checkForUpdates,fontCollection) )

#define IDWriteFactory_CreateCustomFontCollection(This,collectionLoader,collectionKey,collectionKeySize,fontCollection)	\
	( (This)->lpVtbl -> CreateCustomFontCollection(This,collectionLoader,collectionKey,collectionKeySize,fontCollection) )

#define IDWriteFactory_RegisterFontCollectionLoader(This,fontCollectionLoader)	\
	( (This)->lpVtbl -> RegisterFontCollectionLoader(This,fontCollectionLoader) )

#define IDWriteFactory_UnregisterFontCollectionLoader(This,fontCollectionLoader)	\
	( (This)->lpVtbl -> UnregisterFontCollectionLoader(This,fontCollectionLoader) )

#define IDWriteFactory_CreateFontFileReference(This,filePath,lastWriteTime,fontFile)	\
	( (This)->lpVtbl -> CreateFontFileReference(This,filePath,lastWriteTime,fontFile) )

#define IDWriteFactory_CreateCustomFontFileReference(This,fontFileReferenceKey,fontFileReferenceKeySize,fontFileLoader,fontFile)	\
	( (This)->lpVtbl -> CreateCustomFontFileReference(This,fontFileReferenceKey,fontFileReferenceKeySize,fontFileLoader,fontFile) )

#define IDWriteFactory_CreateFontFace(This,fontFaceType,numberOfFiles,fontFiles,faceIndex,fontFace)	\
	( (This)->lpVtbl -> CreateFontFace(This,fontFaceType,numberOfFiles,fontFiles,faceIndex,fontFace) )

#define IDWriteFactory_CreateRenderingParams(This,renderingParams)	\
	( (This)->lpVtbl -> CreateRenderingParams(This,renderingParams) )

#define IDWriteFactory_CreateMonitorRenderingParams(This,monitor,renderingParams)	\
	( (This)->lpVtbl -> CreateMonitorRenderingParams(This,monitor,renderingParams) )

#define IDWriteFactory_CreateCustomRenderingParams(This,gamma,enhancedContrast,clearTypeLevel,pixelGeometry,renderingMode,renderingParams)	\
	( (This)->lpVtbl -> CreateCustomRenderingParams(This,gamma,enhancedContrast,clearTypeLevel,pixelGeometry,renderingMode,renderingParams) )

#define IDWriteFactory_RegisterFontFileLoader(This,fontFileLoader)	\
	( (This)->lpVtbl -> RegisterFontFileLoader(This,fontFileLoader) )

#define IDWriteFactory_UnregisterFontFileLoader(This,fontFileLoader)	\
	( (This)->lpVtbl -> UnregisterFontFileLoader(This,fontFileLoader) )

#define IDWriteFactory_CreateTextFormat(This,fontFamilyName,fontCollection,fontWeight,fontStyle,fontStretch,fontSize,localeName,textFormat)	\
	( (This)->lpVtbl -> CreateTextFormat(This,fontFamilyName,fontCollection,fontWeight,fontStyle,fontStretch,fontSize,localeName,textFormat) )

#define IDWriteFactory_CreateTypography(This,typography)	\
	( (This)->lpVtbl -> CreateTypography(This,typography) )

#define IDWriteFactory_GetGdiInterop(This,gdiInterop)	\
	( (This)->lpVtbl -> GetGdiInterop(This,gdiInterop) )

#define IDWriteFactory_CreateTextLayout(This,string,stringLength,textFormat,maxWidth,maxHeight,textLayout)	\
	( (This)->lpVtbl -> CreateTextLayout(This,string,stringLength,textFormat,maxWidth,maxHeight,textLayout) )

#define IDWriteFactory_CreateGdiCompatibleTextLayout(This,string,stringLength,textFormat,layoutWidth,layoutHeight,pixelsPerDip,transform,useGdiNatural,textLayout)	\
	( (This)->lpVtbl -> CreateGdiCompatibleTextLayout(This,string,stringLength,textFormat,layoutWidth,layoutHeight,pixelsPerDip,transform,useGdiNatural,textLayout) )

#define IDWriteFactory_CreateEllipsisTrimmingSign(This,textFormat,trimmingSign)	\
	( (This)->lpVtbl -> CreateEllipsisTrimmingSign(This,textFormat,trimmingSign) )

#define IDWriteFactory_CreateTextAnalyzer(This,textAnalyzer)	\
	( (This)->lpVtbl -> CreateTextAnalyzer(This,textAnalyzer) )

#define IDWriteFactory_CreateNumberSubstitution(This,numberSubstitutionMethod,localeName,ignoreUserOverride,numberSubstitution)	\
	( (This)->lpVtbl -> CreateNumberSubstitution(This,numberSubstitutionMethod,localeName,ignoreUserOverride,numberSubstitution) )

#define IDWriteFactory_CreateGlyphRunAnalysis(This,glyphRun,pixelsPerDip,transform,renderingMode,measuringMode,baselineOriginX,baselineOriginY,glyphRunAnalysis)	\
	( (This)->lpVtbl -> CreateGlyphRunAnalysis(This,glyphRun,pixelsPerDip,transform,renderingMode,measuringMode,baselineOriginX,baselineOriginY,glyphRunAnalysis) )


/// <summary>
/// Creates a DirectWrite factory object that is used for subsequent creation of individual DirectWrite objects.
/// </summary>
/// <param name="factoryType">Identifies whether the factory object will be shared or isolated.</param>
/// <param name="iid">Identifies the DirectWrite factory interface, such as __uuidof(IDWriteFactory).</param>
/// <param name="factory">Receives the DirectWrite factory object.</param>
/// <returns>
/// Standard HRESULT error code.
/// </returns>
/// <remarks>
/// Obtains DirectWrite factory object that is used for subsequent creation of individual DirectWrite classes.
/// DirectWrite factory contains internal state such as font loader registration and cached font data.
/// In most cases it is recommended to use the shared factory object, because it allows multiple components
/// that use DirectWrite to share internal DirectWrite state and reduce memory usage.
/// However, there are cases when it is desirable to reduce the impact of a component,
/// such as a plug-in from an untrusted source, on the rest of the process by sandboxing and isolating it
/// from the rest of the process components. In such cases, it is recommended to use an isolated factory for the sandboxed
/// component.
/// </remarks>
EXTERN_C HRESULT DWRITE_EXPORT DWriteCreateFactory(
	_In_ DWRITE_FACTORY_TYPE factoryType,
	_In_ REFIID iid,
	_COM_Outptr_ IUnknown** factory
) WIN_NOEXCEPT;

// Macros used to define DirectWrite error codes.
#define FACILITY_DWRITE 0x898
#define DWRITE_ERR_BASE 0x5000
#define MAKE_DWRITE_HR(severity, code) MAKE_HRESULT(severity, FACILITY_DWRITE, (DWRITE_ERR_BASE + code))
#define MAKE_DWRITE_HR_ERR(code) MAKE_DWRITE_HR(SEVERITY_ERROR, code)

// DWrite errors have moved to winerror.h


#endif /* DWRITE_H_INCLUDED */
