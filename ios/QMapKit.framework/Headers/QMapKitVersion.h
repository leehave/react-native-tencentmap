//
//  QMapKitVersion.h
//  QMapKit
//
//  Created by Keith Cao on 2023/3/3.
//  Copyright © 2023 tencent. All rights reserved.
//

#ifndef QMapKitVersion_h
#define QMapKitVersion_h

#import <QMapFoundationKit/QMapFoundationVersion.h>

#define QMapKitVersion 								50302
#define QMapKitRequiredFoundationMinimumVersion		30500

// 依赖库版本检测
#if QMapKitRequiredFoundationMinimumVersion > QMapFoundationVersion
#error "The QMapFoundationKit version is less than minimum required, please update! Any questions please to visit https://lbs.qq.com/"
#endif

#endif /* QMapKitVersion_h */
