//
//  MPMraidInterstitialAdapter.h
//  MoPub
//
//  Created by Andrew He on 12/11/11.
//  Copyright (c) 2012 MoPub, Inc. All rights reserved.
//

#import "MP_MPBaseInterstitialAdapter.h"
#import "MR_MRAdView.h"

@interface MP_MPMraidInterstitialAdapter : MP_MPBaseInterstitialAdapter <MRAdViewDelegate> {
	MR_MRAdView *_adView;
	BOOL _loaded;
}

@end
