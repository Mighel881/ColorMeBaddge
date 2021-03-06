//#import "SpringBoard.h"
#import "CMBColorInfo.h"
#import "CMBIconInfo.h"
#import "external/Anemone/ANEMSettingsManager.h"

typedef NS_ENUM(NSUInteger,BadgeValueType)
{
	kEmptyBadge = 0,
	kNumericBadge,
	kSpecialBadge
};

@interface CMBManager : NSObject <AnemoneEventHandler>
{
	NSMutableDictionary *cachedAppBadgeColors;
	NSMutableDictionary *cachedRandomFolderBadgeColors;
}
+ (instancetype)sharedInstance;
- (CMBColorInfo *)getBadgeColorsForIcon:(id)icon;
- (CMBColorInfo *)getBadgeColorsForApplicationIdentifier:(NSString *)applicationBundleID;
- (CMBColorInfo *)getPreferredAppBadgeColorsForImage:(UIImage *)image;
- (CMBColorInfo *)getBadgeColorsForFolderUsingColorsFromRandomBadge:(CMBIconInfo *)iconInfo preferCachedColors:(BOOL)preferCachedColors;
- (NSInteger)getBadgeValueType:(id)badgeNumberOrString;
- (void)refreshBadges:(NSString *)applicationBundleID;
- (void)refreshBadgesForApplication:(NSString *)applicationBundleID;
- (void)refreshBadgesForAllApplications;
- (CGFloat)getScaledCornerRadius:(CGFloat)fullCornerRadius;
@end

// vim:ft=objc
