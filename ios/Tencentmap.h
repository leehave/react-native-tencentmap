#import <React/RCTBridgeModule.h>
#import <UIKit/UIKit.h>

@interface AppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
}

@property (nonatomic, strong) UIWindow *window;

@end

@interface Tencentmap : NSObject <RCTBridgeModule>

@end
