//
//  QHeatOverlayView.h
//  QMapKit
//
//  Created by Keith Cao on 2020/9/13.
//  Copyright © 2020 tencent. All rights reserved.
//

#ifndef _QHEATOVERLAYVIEW_H_
#define _QHEATOVERLAYVIEW_H_

#import <QMapKit/QMapKit.h>
#import "QHeatOverlay.h"

NS_ASSUME_NONNULL_BEGIN

@interface QHeatOverlayView : QGLOverlayView

- (instancetype)initWithOverlay:(QHeatOverlay *)overlay;

@property (nonatomic, strong, readonly) QHeatOverlay *overlay;

@end

NS_ASSUME_NONNULL_END
#endif
