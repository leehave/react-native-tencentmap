//
//  QMSSearchError.h
//  QMapSearchKit
//
//  Created by tabsong on 2023/2/28.
//  Copyright © 2023 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

// Search Error Domain.
extern NSString * const QMSSearchErrorDomain;

// Search Error Code
// 详细的error code 参考 https://lbs.qq.com/service/webService/webServiceGuide/status
typedef NS_ENUM(NSInteger, QMSSearchErrorCode)
{
    QMSSearchErrorCancelled = -1, /// < 用户主动取消请求.
    QMSSearchErrorOK = 0,  ///< 没有错误
};
