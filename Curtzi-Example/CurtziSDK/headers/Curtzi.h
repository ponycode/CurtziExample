//
//  Curtzi.h
//  Curtzi SDK
//
//	Version 1.0
//
//  Copyright (c) 2014 PonyCode Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CZVisit.h"
#import "CZTag.h"
#import "CZVisitLocation.h"
#import "CZConnectivity.h"
#import "CZLocationServicesAuthorizationDelegate.h"

/* Connectivity Notifications
 *
 * Optionally subscribe to connectivity change notifications
 *
 * Curtzi SDK Requires Bluetooth, Location Services and Internet Connection
 *
 */

extern NSString* const CurtziBluetoothStatusDidChangeNotification;
extern NSString* const CurtziBluetoothIsActiveKey;

/* Curtzi Observer
 *
 * Implement this protocol where your application needs Curtzi Visit updates
 *
 * This is an observer-pattern protocol, which means you can multiple SDK observers
 *
 * See CZSVisiteObserver protocol to observer real-time changes to one of the visits
 * you receive here
 *
 */

@protocol CurtziObserver <NSObject>

@optional

-(void) curtziDidBeginVisit:(CZVisit*) visit;

-(void) curtziDidUpdateVisit:(CZVisit*) visit;

-(void) curtziDidEndVisit:(CZVisit*) visit;

-(void) curtziDidFailWithError:(NSError*) error;

-(void) curtziDidSucceed;

-(void) curtziConnectivityDidChange:(CZConnectivity*)connectivity;

@end


@interface Curtzi : NSObject


/* Start Curtzi
 * 
 * The following code snippet will start Curtzi in your app
 *
 * [Curtzi setKey:@"yourAppKey" andSecret:@"yourAppSecret"];
 * [Curtzi authorizeLocationServices:CZLocationServicesAuthorizationTypeMaskAll];
 * [Curtzi start];
 */

+(void) setClientID:(NSString*) appKey andSecret:(NSString*) appSecret;

+(void) start;

+(void) stop;


/* Location Authorization
 *
 * Optional - implement your own delegate to provide your own prompts
 * and help Curtzi handle location authorization
 *
 * CurtziSDK will hold a weak reference to your delegate;
 *
 * DEFAULT: if you do not create your own delegate, the default delegate
 * will 1) Prompt the user to choose an authorization type
 *      2) Request the selected authorization from CoreLocation
 *		3) If the user has already denied location authorization, re-prompt the user
 *		4) If the user accepts the re-prompt, send them to Application Settings
 *		5) If the user has authorized WhenInUse, and you included Always in 'requestsAuthorizationTypes'
 *		   Prompt the user to upgrade
 *		6) If the user accepts, send them to Application Settings
 */

+(void) setLocationAuthorizationDelegate:(id<CZLocationServicesAuthorizationDelegate>) locationAuthorizationDelegate;

+(void) authorizeLocationServices:(CZLocationServicesAuthorizationTypeMask) requestsAuthorizationTypes;



/* Become an observer for Curtzi events
 *
 * This is an observer-pattern protocol, which means that you can have multiple SDK observers
 * Curtzi keeps a auto-zeroing weak reference to your object
 */

+(void) addCurtziObserver:(id<CurtziObserver>) observer;
+(void) removeCurtziObserver:(id<CurtziObserver>) observer;


/* Visits
 *
 * An Array of all current visits
 * Usefull to get initial state on start, in ascending proximity order (near to far)
 *
 * See also curtziDidBeginVisit: observer method
 */
+(NSArray*) visits;


/* Connectivity
 *
 * Current connectivity (bluetooth, location, etc.) as observed by Curtzi
 *
 * See also the curtziConnectivityDidChange: observer methods
 */
+(CZConnectivity*)connectivity;


/* Optionally Identify Your User
 *
 * Provide any string that will identify your user for your application.
 * This string will be used to group visit data in the Curtzi Analytics Dashboard
 *
 * Do not use any personal user data, as this information will be stored on
 * Curtzi's servers.
 */

+(void) identifyUser:(NSString*) userIdentification;


+(void) setLoggingLevel:(NSUInteger)level;		// 0=Debug, 1=Info, 2=Warning, 3=Error

+(NSString*) version;	// The version of this SDK


@end
