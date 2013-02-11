//
//  MPLogging.h
//  MoPub
//
//  Created by Andrew He on 2/10/11.
//  Copyright 2011 MoPub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MPConstants.h"

// Lower = finer-grained logs.
typedef enum 
{
	MPLogLevelAll		= 0,
	MPLogLevelTrace		= 10,
	MPLogLevelDebug		= 20,
	MPLogLevelInfo		= 30,
	MPLogLevelWarn		= 40,
	MPLogLevelError		= 50,
	MPLogLevelFatal		= 60,
	MPLogLevelOff		= 70
} MPLogLevel;

MPLogLevel MP_MPLogGetLevel(void);
void MP_MPLogSetLevel(MPLogLevel level);
void _MP_MPLogTrace(NSString *format, ...);
void _MP_MPLogDebug(NSString *format, ...);
void _MP_MPLogInfo(NSString *format, ...);
void _MP_MPLogWarn(NSString *format, ...);
void _MP_MPLogError(NSString *format, ...);
void _MP_MPLogFatal(NSString *format, ...);

#if MP_DEBUG_MODE

#define MPLogTrace(...) _MP_MPLogTrace(__VA_ARGS__)
#define MPLogDebug(...) _MP_MPLogDebug(__VA_ARGS__)
#define MPLogInfo(...) _MP_MPLogInfo(__VA_ARGS__)
#define MPLogWarn(...) _MP_MPLogWarn(__VA_ARGS__)
#define MPLogError(...) _MP_MPLogError(__VA_ARGS__)
#define MPLogFatal(...) _MP_MPLogFatal(__VA_ARGS__)

#else

#define MPLogTrace(...) {}
#define MPLogDebug(...) {}
#define MPLogInfo(...) {}
#define MPLogWarn(...) {}
#define MPLogError(...) {}
#define MPLogFatal(...) {}

#endif
