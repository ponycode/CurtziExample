//
//  CZConnectivity.h
//  Curtzi SDK
//
//  Created by Josh Kennedy on 10/29/14.
//  Copyright (c) 2014 PonyCode Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, CZLocationServiceStatus){
	CZLocationServiceStatusUndetermined,
	CZLocationServiceStatusNoHardware,
	CZLocationServiceStatusWhenInUse,
	CZLocationServiceStatusAlways,
	CZLocationServiceStatusDenied,
	CZLocationServiceStatusRestricted
};

typedef NS_ENUM( NSInteger, CZLocationServicesAuthorizationType ){
	CZLocationServicesAuthorizationTypeNone				= 1 << 0,
	CZLocationServicesAuthorizationTypeAlways			= 1 << 1,
	CZLocationServicesAuthorizationTypeWhenInUse		= 1 << 2,
	CZLocationServicesAuthorizationTypeAll				= 0x7
};

typedef NSUInteger CZLocationServicesAuthorizationTypeMask;	// mask of CZLocationServicesAuthorizationType values

typedef NS_ENUM( NSInteger, CZNetworkReachabilityStatus){
	CZNetworkStatusNotReachable,
	CZNetworkStatusReachableViaWiFi,
	CZNetworkStatusReachableViaWWAN
};


@interface CZConnectivity : NSObject

@property (nonatomic,assign) BOOL curtziIsPossibleOnThisDevice;
@property (nonatomic,assign) BOOL curtziIsCurrentlySupported;

@property (nonatomic,assign) BOOL bluetoothIsActive;

@property (nonatomic,assign) BOOL locationIsAuthorized;
@property (nonatomic,assign) CZLocationServiceStatus locationAuthorizationStatus;

@property (nonatomic,assign) CZNetworkReachabilityStatus networkReachabilityStatus;

@end
