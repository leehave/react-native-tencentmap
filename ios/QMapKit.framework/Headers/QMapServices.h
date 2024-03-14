//
//  QMapServices.h
//  QMapKit
//
//  Copyright (c) 2017年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 地图服务类
 */
@interface QMapServices : NSObject

/**
 * @brief 获取单例
 */
+ (nonnull QMapServices *)sharedServices;

/**
 * @brief apikey 在官网申请的服务授权标识的key
 */
@property (nonnull, copy, nonatomic) NSString *APIKey;

/**
 * @brief 自定义的用户ID，用于与开发者联调查询服务端日志的唯一标识
 */
@property (nullable, nonatomic, copy) NSString *userId;

/**
 * @brief 获取地图SDK的版本号
 */
- (NSString * _Nonnull)sdkVersion;

/**
 * @brief 隐私合规接口, 必须在地图初始化前调用, 默认为false
 *        设置为false, 地图实例返回nil, 地图功能不能使用
 *        隐私政策官网: https://lbs.qq.com/userAgreements/agreements/privacy
 */
- (void)setPrivacyAgreement:(BOOL)isAgree;

/**
*  @brief  是否开启debug 日志. 默认为NO.
*  @important: 正式发布版，切记不要开启.
*/
@property (nonatomic) BOOL enableDebugLog;

@end
