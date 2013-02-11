//
//  MPMraidAdapter.h
//  MoPub
//
//  Created by Andrew He on 10/29/11.
//  Copyright (c) 2011 MoPub, Inc. All rights reserved.
//

#import "MP_MPBaseAdapter.h"
#import "MR_MRAdView.h"

@interface MP_MPMraidAdapter : MP_MPBaseAdapter <MRAdViewDelegate> {
    MR_MRAdView *_adView;
}
@property(nonatomic,retain) MR_MRAdView* _adView;

@end
