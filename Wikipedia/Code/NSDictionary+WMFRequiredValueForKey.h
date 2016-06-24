//
//  NSDictionary+WMFRequiredValueForKey.h
//  Wikipedia
//
//  Created by Brian Gerstle on 2/11/16.
//  Copyright © 2016 Wikimedia Foundation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const WMFInvalidValueForKeyErrorDomain;
extern NSString *const WMFFailingDictionaryUserInfoKey;

typedef NS_ENUM(UInt32, WMFInvalidValueForKeyError) {
    WMFInvalidValueForKeyErrorNoValue,
    WMFInvalidValueForKeyErrorIncorrectType
};

@interface NSDictionary (WMFRequiredValueForKey)

- (nullable id)wmf_instanceOfClass:(Class)type
                            forKey:(NSString *)key
                             error:(NSError *_Nullable __autoreleasing *)outError;

@end

NS_ASSUME_NONNULL_END
