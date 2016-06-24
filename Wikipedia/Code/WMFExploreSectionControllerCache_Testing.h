//
//  WMFExploreSectionControllerCache_Testing.h
//  Wikipedia
//
//  Created by Brian Gerstle on 2/26/16.
//  Copyright © 2016 Wikimedia Foundation. All rights reserved.
//

#import "WMFExploreSectionControllerCache.h"

NS_ASSUME_NONNULL_BEGIN

@interface WMFExploreSectionControllerCache ()

@property (nonatomic, strong, readwrite) MWKDataStore *dataStore;

/**
 *  Cache of section controllers keyed by the section they were created for.
 *
 *  Controllers can be evicted at any time when the cache is asked to release memory by the operating system.
 */
@property (nonatomic, strong) NSCache *sectionControllersBySection;

/**
 *  Reverse map of @c sectionControllersBySection which is used to retrieve sections by their associated controller.
 *
 *  @note
 *  Internally created as weak-to-weak in order to ensure the canonical store (@c sectionControllersBySection) has full
 *  authority over lifecycle management.
 */
@property (nonatomic, strong) NSMapTable *reverseLookup;

@end

NS_ASSUME_NONNULL_END
