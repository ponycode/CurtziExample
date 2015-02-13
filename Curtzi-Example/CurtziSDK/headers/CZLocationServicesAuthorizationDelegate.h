//
//  CZLocationServicesAuthorizationDelegate.h
//  CurtziCore
//
//  Created by Scott Eklund on 1/30/15.
//  Copyright (c) 2015 PonyCode Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CZConnectivity.h"

typedef NS_ENUM( NSInteger, CZLocationAuthorizationPrePromptResponse){
	CZLocationAuthorizationPrePromptResponseLater,
	CZLocationAuthorizationPrePromptResponseWhenInUse,
	CZLocationAuthorizationPrePromptResponseAlways
};

typedef NS_ENUM( NSInteger, CZLocationAuthorizationRePromptResponse){
	CZLocationAuthorizationRePromptResponseNo,
	CZLocationAuthorizationRePromptResponseGotoSettings
};

typedef NS_ENUM( NSInteger, CZLocationAuthorizationUpgradeResponse){
	CZLocationAuthorizationUpgradePromptResponseNo,
	CZLocationAuthorizationUpgradePromptResponseYes
};





@protocol CZLocationServicesAuthorizationControllerProtocol <NSObject>

-(void) prePromptResponse:(CZLocationAuthorizationPrePromptResponse)response;

-(void) rePromptResponse:(CZLocationAuthorizationRePromptResponse)response;

-(void) upgradePromptResponse:(CZLocationAuthorizationUpgradeResponse)response;

@end



@class CZLocationServicesAuthorizationController;



@protocol CZLocationServicesAuthorizationDelegate <NSObject>

-(BOOL) shouldPresentAuthorizationPrePrompt;

-(void) presentAuthorizationPrePrompt:(CZLocationServicesAuthorizationTypeMask)requestsAuthorizationTypes;

-(BOOL) shouldPresentAuthorizationRePrompt;

-(void) presentAuthorizationRePrompt:(CZLocationServicesAuthorizationTypeMask)requestsAuthorizationTypes;

-(BOOL) shouldPResentAuthorizationUpgradePrompt;

-(void) presentAuthorizationUpgradePrompt:(CZLocationServicesAuthorizationTypeMask)requestsAuthorizationTypes;

@property (nonatomic, weak) id<CZLocationServicesAuthorizationControllerProtocol> controller;

@end
