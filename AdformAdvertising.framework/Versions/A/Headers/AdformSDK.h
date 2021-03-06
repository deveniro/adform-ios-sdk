//
//  AdformSDK.h
//  AdformAdvertising
//
//  Copyright (c) 2014 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Generic Adform Advertising SDK class, used to provide global functions.
 */
@interface AdformSDK : NSObject

/**
 Returns SDK version as a string value.
 */
+ (NSString *)sdkVersion;


/**
 Use this method to set publisher id.
 
 You can also add custom key-value pair data to identify the user, that way you will target ads to your users even more accurately, e.g. @{@"gender": @"male"}.
 This parameter works globally to all ad placements.
 This parameter can be modified only before the first successful ad request (you can still set it later if you haven't done it before requesting ads).
 
 @param publisherId An NSInteger with publisher id.
 @param customData An NSDictionary with custom key-value pair data.
 */
+ (void)setPublisherId:(NSInteger)publisherId andCustomData:(NSDictionary *)customData;


/**
 Use this property to allow or deny the sdk to use current user location.
 
 By default use of location is disabled.
 Enabling the use of current user location will allow sdk to server ads more accurately.
 
 @warning You need to define NSLocationWhenInUseUsageDescription key in your applications info.plist file, if you don't have one.
 Set it's text to "Your location is used to show relevant ads nearby." or its translation.
 
 @param allow Boolean value indicating if use of current user location should be allowed or denied.
 */
+ (void)setAllowUseOfLocation:(BOOL )allow;

/**
 You can use this to check if the use of current user location is allowed.
 */
+ (BOOL)isUseOfLocationAllowed;

/**
 Sets server domain.
 */
+ (void)setDomain:(NSInteger )domain;


/**
 Use this method to define how the sdk should open external links.
 
 If set to true - sdk will open external links in in-app browser,
 otherwise the sdk will open links in Safari app.
 By default sdk uses Safari app to open external links.
 
 @param shouldOpen A boolean value indicating if app should open external links in in-app browser.
 */
+ (void)setOpenLinksInAppBrowser:(BOOL )shouldOpen;

/**
 Identifies how the sdk is going to open external links.
 
 @return If true - sdk is going to open external links in in-app browser,
 otherwise - in Safari app.
 */
+ (BOOL)shouldOpenLinksInAppBrowser;

/**
 Enables or disables HTTPS support. 

 By default sdk uses HTTPS because that is required by Apple on iOS 9+ platforms.
 It is not recomended, but you can use this method to disable HTTPS.
 */
+ (void)setHTTPSEnabled:(BOOL)enabled;

/**
 Identifies if sdk is using the HTTPS protocol for network communications.
 
 @return True - if sdk is using HTTPS, otherwise - false.
 */
+ (BOOL)isHTTPSEnabled;

/**
 Sets a custom string resource for the sdk.
 
 This method can be used as one of the options to translate sdk string resources.
 You can use it to define custom strings for storePicture confirmation alert view.
 
 Another way to localize sdk resources is to add these strings to applications localizable.strings files
 and translate them there. You should add default string values defined at the definitions
 of the constants provided bellow as keys for localizable strings.
 
 Available keys: kAFStorePictureAlertMessageKey, kAFStorePictureAlertSaveButtonTitleKey, kAFStorePictureAlertCancelButtonTitleKey.
 */
+ (void)setStringResource:(NSString *)resource forKey:(NSString *)key;

/**
 Returns a previously set custom string resource.
 
 Available keys: kAFStorePictureAlertMessageKey, kAFStorePictureAlertSaveButtonTitleKey, kAFStorePictureAlertCancelButtonTitleKey.
 */
+ (NSString *)stringResourceForKey:(NSString *)key;

@end

@interface AdformSDK ()

// Deprecated

/**
 Use this property to allow or deny the sdk to use current user location.
 
 By default use of location is disabled.
 Enabling the use of current user location will allow sdk to server ads more accurately.
 
 @warning You need to define NSLocationWhenInUseUsageDescription key in your applications info.plist file, if you don't have one.
 Set it's text to "Your location is used to show relevant ads nearby." or its translation.
 
 @param allowed Boolean value indicating if use of current user location should be allowed or denied.
 */
+ (void)allowUseOfLocation:(BOOL )allowed __deprecated_msg("Use 'setAllowUseOfLocation:' instead.");


/**
 Use this method to define how the sdk should open external links.
 
 If set to true - sdk will open external links in Safari app,
 otherwise the sdk will open links in internal browser.
 By default sdk uses Safari app to open external links.
 
 @attention On iOS 9 applications are forced to use HTTPS,
 therefore if you choose to use internal browser
 but don't have the ATS exception configured to allow HTTP use,
 some of the links may not load in the browser.
 In this case we recomend to use the Safari app to open external links.
 
 @param shouldOpen A boolean value indicating if app should open external links in safari browser.
 */
+ (void)setShouldOpenLinksInSafari:(BOOL )shouldOpen __deprecated_msg("Use 'setOpenLinksInAppBrowser:' instead.");

/**
 Identifies how the sdk is going to open external links.
 
 @return If true - sdk is going to open external links in Safari app,
 otherwise - in internal browser.
 */
+ (BOOL)shouldOpenLinksInSafari __deprecated_msg("Use 'shouldOpenLinksInAppBrowser:' instead.");

@end