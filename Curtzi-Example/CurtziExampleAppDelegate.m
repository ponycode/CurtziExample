//
//  CurtziExampleAppDelegate.m
//  Curtzi-Example
//

#import "CurtziExampleAppDelegate.h"
#import "Curtzi.h"

@interface CurtziExampleAppDelegate ()<CurtziObserver>
@end

@implementation CurtziExampleAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
	[Curtzi setClientID:@"yourAppClientID" andSecret:@"yourAppSecret"];
	[Curtzi start];
	return YES;
}

@end
