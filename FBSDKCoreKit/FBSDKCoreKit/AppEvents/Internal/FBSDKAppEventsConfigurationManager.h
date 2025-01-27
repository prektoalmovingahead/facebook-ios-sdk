/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

typedef void (^FBSDKAppEventsConfigurationManagerBlock)(void);
@protocol FBSDKDataPersisting;
@protocol FBSDKSettings;
@protocol FBSDKGraphRequestFactory;
@protocol FBSDKGraphRequestConnectionFactory;
@protocol FBSDKAppEventsConfiguration;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(AppEventsConfigurationManager)
@interface FBSDKAppEventsConfigurationManager : NSObject

@property (class, nonatomic, readonly) FBSDKAppEventsConfigurationManager *shared;

@property (nonatomic, readonly) id<FBSDKAppEventsConfiguration> cachedAppEventsConfiguration;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

// UNCRUSTIFY_FORMAT_OFF
+ (void)     configureWithStore:(id<FBSDKDataPersisting>)store
                       settings:(id<FBSDKSettings>)settings
            graphRequestFactory:(id<FBSDKGraphRequestFactory>)graphRequestFactory
  graphRequestConnectionFactory:(id<FBSDKGraphRequestConnectionFactory>)graphRequestConnectionFactory
NS_SWIFT_NAME(configure(store:settings:graphRequestFactory:graphRequestConnectionFactory:));
// UNCRUSTIFY_FORMAT_ON

- (void)loadAppEventsConfigurationWithBlock:(FBSDKAppEventsConfigurationManagerBlock)block;

@end

NS_ASSUME_NONNULL_END
