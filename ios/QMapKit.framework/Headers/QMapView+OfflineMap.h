//
//  QMapView+OfflineMap.h
//  QMapKit
//
//  Created by Keith Cao on 2020/5/13.
//  Copyright © 2020 tencent. All rights reserved.
//

#import <QMapKit/QMapKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface QMapView (OfflineMap)

/**
 * @brief 离线地图开关, 默认为 NO
 */
@property (nonatomic, assign, getter = isOfflineMapEnable) BOOL offlineMapEnable;

@end

NS_ASSUME_NONNULL_END
