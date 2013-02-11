//
//  MPAdView+MPAdManagerFriend.h
//  MoPub
//
//  Created by Haydn Dufrene on 6/22/11.
//  Copyright 2011 MoPub, Inc. All rights reserved.
//

#import "MP_MPAdManager.h"
#import "MP_MPAdView.h"

@interface MP_MPAdView (MPAdManagerFriend)

@property (nonatomic, retain) MP_MPAdManager *adManager;
@property (nonatomic, retain) UIView *adContentView;
@property (nonatomic, assign) CGSize originalSize;

- (void)backFillWithNothing;

@end
