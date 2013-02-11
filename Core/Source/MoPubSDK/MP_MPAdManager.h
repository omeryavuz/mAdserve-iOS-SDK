//
//  MPAdManager.h
//  MoPub
//
//  Created by Haydn Dufrene on 6/15/11.
//  Copyright 2011 MoPub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "MP_MPStore.h"
#import "MP_MPBaseAdapter.h"
#import "MP_MPAdBrowserController.h"
#import "MP_MPProgressOverlayView.h"

extern NSString * const k_kTimerNotificationName;
extern NSString * const k_kErrorDomain;
extern NSString * const k_kMoPubUrlScheme;
extern NSString * const k_kMoPubCloseHost;
extern NSString * const k_kMoPubFinishLoadHost;
extern NSString * const k_kMoPubFailLoadHost;
extern NSString * const k_kMoPubInAppHost;
extern NSString * const k_kMoPubCustomHost;
extern NSString * const k_kMoPubInterfaceOrientationPortraitId;
extern NSString * const k_kMoPubInterfaceOrientationLandscapeId;
extern const CGFloat k_kMoPubRequestTimeoutInterval;
extern const CGFloat k_kMoPubRequestRetryInterval;
extern NSString * const k_kClickthroughHeaderKey;
extern NSString * const k_kLaunchpageHeaderKey;
extern NSString * const k_kFailUrlHeaderKey;
extern NSString * const k_kImpressionTrackerHeaderKey;
extern NSString * const k_kInterceptLinksHeaderKey;
extern NSString * const k_kScrollableHeaderKey;
extern NSString * const k_kWidthHeaderKey;
extern NSString * const k_kHeightHeaderKey;
extern NSString * const k_kRefreshTimeHeaderKey;
extern NSString * const k_kAnimationHeaderKey;
extern NSString * const k_kAdTypeHeaderKey;
extern NSString * const k_kNetworkTypeHeaderKey;
extern NSString * const k_kAdTypeHtml;
extern NSString * const k_kAdTypeClear;

@class MP_MPAdView, MP_MPTimer, MP_MPTimerTarget, MP_MPBaseAdapter;

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 50000 // iOS 5.0+
@interface MP_MPAdManager : NSObject <MPAdapterDelegate, MPAdBrowserControllerDelegate,
    UIWebViewDelegate, NSURLConnectionDataDelegate, MPProgressOverlayViewDelegate>
#else
@interface MP_MPAdManager : NSObject <MPAdapterDelegate, MPAdBrowserControllerDelegate, 
    UIWebViewDelegate, MPProgressOverlayViewDelegate>
#endif
{
	MP_MPAdView *_adView;

	// Ad unit identifier for the ad view.
	NSString *_adUnitId;

	// Targeting parameters.
	NSString *_keywords;

	// URL for initial MoPub ad request.
	NSURL *_URL;

	// Whether this ad view is currently loading an ad.
	BOOL _isLoading;

	// Whether the ad is currently in the middle of a user-triggered action.
	BOOL _adActionInProgress;

    NSMutableURLRequest *_request;
    
	NSURLConnection *_conn;

	// Connection data object for ad request.
	NSMutableData *_data;

	// Dictionary of response headers for the current ad request.
	NSDictionary *_headers;

	// Pool of webviews being used as HTML ads.
	NSMutableSet *_webviewPool;

	// Current adapter being used for serving native ads.
	MP_MPBaseAdapter *_currentAdapter;

	// Previous adapter.
	MP_MPBaseAdapter *_previousAdapter;

	// Click-tracking URL.
	NSURL *_clickURL;

	// We often need to intercept ad navigation that is not the result of a
	// click. This represents a URL prefix for links we'd like to intercept.
	NSURL *_interceptURL;

	// Fall-back URL if an ad request fails.
	NSURL *_failURL;

	// Impression-tracking URL.
	NSURL *_impTrackerURL;

	// Whether we should intercept any sort of ad navigation.
	BOOL _shouldInterceptLinks;

	// Timer that sends a -forceRefreshAd message upon firing, with a time interval handed
	// down from the server. You can set the desired interval for any ad unit using 
	// the MoPub web interface.
	MP_MPTimer *_autorefreshTimer;

	// Used as the target object for the MPTimer, in order to avoid a retain cycle (see MPTimer.h).
	MP_MPTimerTarget *_timerTarget;

	// Whether the ad view ignores autorefresh values sent down from the server. If YES,
	// the ad view will never refresh once it has a valid ad.
	BOOL _ignoresAutorefresh;

	// Whether the autorefresh timer needs to be scheduled. Use case: during a user-triggered ad 
	// action, we must postpone any attempted timer scheduling until the action ends. This flag 
	// allows the "action-ended" callbacks to decide whether the timer needs to be re-scheduled.
	BOOL _autorefreshTimerNeedsScheduling;
    
    BOOL _previousIgnoresAutorefresh;
    
    BOOL _shouldLoadMRAIDAd;
    
    MP_MPAdBrowserController *_currentBrowserController;
}

@property (nonatomic, readonly) MP_MPAdView *adView;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////

@interface MP_MPInterstitialAdManager : MP_MPAdManager

@end
