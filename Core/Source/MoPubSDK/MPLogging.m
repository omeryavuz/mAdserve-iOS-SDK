//
//  MPLogging.m
//  MoPub
//
//  Created by Andrew He on 2/10/11.
//  Copyright 2011 MoPub, Inc. All rights reserved.
//

#import "MPLogging.h"

static MPLogLevel MPLOG_LEVEL = MPLogLevelInfo;

MPLogLevel MP_MPLogGetLevel()
{
	return MPLOG_LEVEL;
}

void MP_MPLogSetLevel(MPLogLevel level)
{
	MPLOG_LEVEL = level;
}

void _MP_MPLogTrace(NSString *format, ...)
{
	if (MPLOG_LEVEL <= MPLogLevelTrace)
    {
		format = [NSString stringWithFormat:@"MOPUB: %@", format];
        va_list args;
        va_start(args, format);
        NSLogv(format, args);
        va_end(args);
    }
}

void _MP_MPLogDebug(NSString *format, ...)
{
	if (MPLOG_LEVEL <= MPLogLevelDebug)
    {
		format = [NSString stringWithFormat:@"MOPUB: %@", format];
        va_list args;
        va_start(args, format);
        NSLogv(format, args);
        va_end(args);
    }
}

void _MP_MPLogWarn(NSString *format, ...)
{
	if (MPLOG_LEVEL <= MPLogLevelWarn)
    {
		format = [NSString stringWithFormat:@"MOPUB: %@", format];
        va_list args;
        va_start(args, format);
        NSLogv(format, args);
        va_end(args);
    }
}

void _MP_MPLogInfo(NSString *format, ...)
{
	if (MPLOG_LEVEL <= MPLogLevelInfo)
    {
		format = [NSString stringWithFormat:@"MOPUB: %@", format];
        va_list args;
        va_start(args, format);
        NSLogv(format, args);
        va_end(args);
    }
}

void _MP_MPLogError(NSString *format, ...)
{
	if (MPLOG_LEVEL <= MPLogLevelError)
    {
		format = [NSString stringWithFormat:@"MOPUB: %@", format];
        va_list args;
        va_start(args, format);
        NSLogv(format, args);
        va_end(args);
    }
}

void _MP_MPLogFatal(NSString *format, ...)
{
	if (MPLOG_LEVEL <= MPLogLevelFatal)
    {
		format = [NSString stringWithFormat:@"MOPUB: %@", format];
        va_list args;
        va_start(args, format);
        NSLogv(format, args);
        va_end(args);
    }
}