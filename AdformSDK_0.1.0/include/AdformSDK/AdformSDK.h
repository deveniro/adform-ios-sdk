//
//  AdformSDK.h
//  AdformSDK
//
//  Created by Vladas on 23/04/14.
//  Copyright (c) 2014 adform. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AFBannerView.h"
#import "AFInterstitialAdView.h"

/**
 Generic AdformSDK class, used to import public headers and provide global functions
 */
@interface AdformSDK : NSObject

/**
 Returns SDK version as a string value
 */
+ (NSString *)version;

/**
 Use this method to set publisher id.
 
 You can also add custom key-value pair data to target ads to your users even more accurately, e.g. @{@"gender": @"male"}.
 This parameter works globally to all ad placements.
 This parameter can be modified only before the first successful ad request (you can stil set it later if you haven't done it before requesting ads).
 
 @param publisherId An NSInteger with publisher id.
 @param customData An NSDictionary with custom key-value pair data.
 */
+ (void)setPublisherId:(NSInteger)publisherId andCustomData:(NSDictionary *)customData;

@end
