/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_MAPVIEW_H
#define S3E_EXT_MAPVIEW_H

#include <s3eTypes.h>

enum s3eMapViewCallback
{
	S3E_MAPVIEW_CALLBACK_POI_SELECTED, // User has tapped/clicked on a POI
	S3E_MAPVIEW_CALLBACK_MAX
};

struct s3eMapView;
struct s3eMapViewPOI;
struct s3eMapViewCoord {
	double lat;
	double lng;
	s3eMapViewCoord(double _lat, double _lng) : lat(_lat), lng(_lng) {}
};
struct s3eMapViewSpan {
	double latDelta;
	double lngDelta;
	s3eMapViewSpan(double _latDelta, double _lngDelta) : latDelta(_latDelta), lngDelta(_lngDelta) {}
};
enum s3eMapViewType {
	S3E_MAPVIEW_TYPE_STANDARD,
	S3E_MAPVIEW_TYPE_SATELLITE,
	S3E_MAPVIEW_TYPE_HYBRID
};

// Helpers to convert references to pointers.  These are required because only POD data can be passed as arguments to methods that run on the OS thread.
extern "C" {
	void _s3eMapViewGoTo(s3eMapView* pMapView, const s3eMapViewCoord* center, const s3eMapViewSpan* span, bool animate);
	s3eMapViewPOI* _s3eMapViewAddPOI(s3eMapView* pMapView, const s3eMapViewCoord* location, const char* title, const char* subtitle, bool clickable, void* clickData);
}
inline void s3eMapViewGoTo(s3eMapView* pMapView, const s3eMapViewCoord& center, const s3eMapViewSpan& span, bool animate)
	{ _s3eMapViewGoTo(pMapView, &center, &span, animate); }
inline s3eMapViewPOI* s3eMapViewAddPOI(s3eMapView* pMapView, const s3eMapViewCoord location, const char* title = NULL, const char* subtitle = NULL, bool clickable = false, void* clickData = NULL)
	{ return _s3eMapViewAddPOI(pMapView, &location, title, subtitle, clickable, clickData); }
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the MapView extension is available.
 */
s3eBool s3eMapViewAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref s3eMapViewCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userdata Value to pass to the @e userdata parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see s3eMapViewUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref s3eMapViewCallback enum.
 */
s3eResult s3eMapViewRegister(s3eMapViewCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback for which to register.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @note For more information on the systemData passed as a parameter to the callback
 * registered using this function, see the s3eMapViewCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 * @see s3eMapViewRegister
 */
s3eResult s3eMapViewUnRegister(s3eMapViewCallback cbid, s3eCallback fn);

s3eMapView* s3eMapViewCreate();

s3eResult s3eMapViewDestroy(s3eMapView* pMapView);

void s3eMapViewSetScreenRect(s3eMapView* pMapView, int x, int y, int w, int h);

void s3eMapViewSetVisible(s3eMapView* pMapView, bool visible);

void s3eMapViewSetType(s3eMapView* pMapView, s3eMapViewType type);

void s3eMapViewSetShowUserLocation(s3eMapView* pMapView, bool show);

void _s3eMapViewGoTo(s3eMapView* pMapView, const s3eMapViewCoord* center, const s3eMapViewSpan* span, bool animate);

s3eMapViewPOI* _s3eMapViewAddPOI(s3eMapView* pMapView, const s3eMapViewCoord* location, const char* title, const char* subtitle, bool clickable, void* clickData);

void s3eMapViewRemovePOI(s3eMapView* pMapView, s3eMapViewPOI* poi);

const char* s3eMapViewGetPlatformLicensingString();

S3E_END_C_DECL

#endif /* !S3E_EXT_MAPVIEW_H */
