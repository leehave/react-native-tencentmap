//
//  QMSSearchServices.h
//  QMapSearchKit
//
//  Created by xfang on 14/11/5.
//  Copyright (c) 2014年 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 *  @brief  Search检索的配置类
 */
@interface QMSSearchServices : NSObject

/*!
 *  @brief  生成QMSSearchServices单例
 *
 *  @return QMSSearchServices单例
 */
+ (instancetype)sharedServices;

/*!
 *  @brief  腾讯web service key
 */
@property (nonatomic, copy) NSString *apiKey;

/*！
 *	@brief 腾讯web service的SecretKey
 */
@property (nonatomic, copy) NSString *secretKey;

/*!
 *  @brief  版本号 v1.6.1
 */
@property (nonatomic, readonly) NSString *SDKVersion;

@end
