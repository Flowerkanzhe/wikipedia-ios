
#import "WMFArticleRequestSerializer.h"
#import "WMFNetworkUtilities.h"
#import "MWKTitle.h"
#import "UIScreen+WMFImageWidth.h"

@implementation WMFArticleRequestSerializer


- (NSURLRequest*)requestBySerializingRequest:(NSURLRequest*)request
                              withParameters:(id)parameters
                                       error:(NSError* __autoreleasing*)error {
    NSMutableDictionary* serializedParams = [self paramsForTitle:(MWKTitle*)parameters];

    return [super requestBySerializingRequest:request withParameters:serializedParams error:error];
}

- (NSMutableDictionary*)paramsForTitle:(MWKTitle*)title {
    NSMutableDictionary* params = @{
        @"format": @"json",
        @"action": @"mobileview",
        @"sectionprop": WMFJoinedPropertyParameters(@[@"toclevel", @"line", @"anchor", @"level", @"number",
                                                      @"fromtitle", @"index"]),
        @"noheadings": @"true",
        @"sections": @"all",
        @"page": title.text,
        @"thumbwidth": [[UIScreen mainScreen] wmf_leadImageWidthForScale],
        @"prop": WMFJoinedPropertyParameters(@[@"sections", @"text", @"lastmodified", @"lastmodifiedby",
                                               @"languagecount", @"id", @"protection", @"editable", @"displaytitle",
                                               @"thumb", @"description", @"image", @"revision"])
    }.mutableCopy;

    return params;
}

@end
