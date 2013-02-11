//
//  MPInterstitialAdController+MPCustomEventAdapterFriend.h
//  MoPub
//
//  Created by Andrew He on 6/25/12.
//  Copyright (c) 2012 MoPub, Inc. All rights reserved.
//

#import "MP_MPInterstitialAdController.h"

@interface MP_MPInterstitialAdController (MPCustomEventAdapterFriend)

- (id<MPInterstitialAdControllerDelegate>)customEventDelegate;

@end
