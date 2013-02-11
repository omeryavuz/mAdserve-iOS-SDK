#import <objc/runtime.h>
#import "UIButton+AdSdk.h"

static char const * const ObjectTagKey = "ObjectTag";

@implementation UIButton (AdSdk)

@dynamic objectTag;

- (id)objectTag {
    return objc_getAssociatedObject(self, ObjectTagKey);
}

- (void)setObjectTag:(id)newObjectTag {
    // By specifying OBJC_ASSOCIATION_RETAIN_NONATOMIC, we tell the runtime to retain the value for us
    objc_setAssociatedObject(self, ObjectTagKey, newObjectTag, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end
