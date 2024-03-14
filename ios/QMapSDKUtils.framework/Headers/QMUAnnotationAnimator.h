//
//  QMUAnnotationAnimator.h
//  QMapSDKUtils
//
//  Created by 薛程 on 2019/1/8.
//  Copyright © 2019年 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <QMapKit/QAnnotationView.h>

/**
 * @brief  位置协议.
 */
@protocol QMULocation <NSObject>

@required

/**
 * @brief  经纬度信息.
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@end

/**
 * @brief 平移动画状态
 */
typedef enum _QMUAnnotationAnimationStatus
{
	/// 动画插值中
	QMUAnnotationAnimation_Interpolating = 0,
	
	/// 动画完整结束
	QMUAnnotationAnimation_Complete
}QMUAnnotationAnimationStatus;

/**
 * @brief 平移动画callback信息
 */
typedef struct
{
	/// 当前插值点的坐标
	CLLocationCoordinate2D coordinate;
	
	/// 当前点处于原始移动路线点串中的下标(便于开发者使用路线擦除接口)
	int index;
	
	/// 动画的状态
	QMUAnnotationAnimationStatus status;
	
}QMUAnnotationAnimationInfo;

/**
 * @brief 平移动画callback
 */
typedef void (^QMUAnnotationAnimationCallBack)(QMUAnnotationAnimationInfo info);

/**
 * @brief  平滑移动控制类.
 */
@interface QMUAnnotationAnimator : NSObject

/**
 * @brief  执行平滑移动动画. 该方法支仅持地图在2D正北状态下进行.
 * @param annotationView  平滑移动的对象
 * @param locations     平滑移动需要经过的经纬度坐标点串
 * @param duration        平滑移动时间
 * @param needRotate      平滑移动过程中annotationView是否需要沿移动方向执行旋转动画
 */
+ (void)translateWithAnnotationView:(QAnnotationView *)annotationView
                          locations:(NSArray<id <QMULocation> > *)locations
                           duration:(CFTimeInterval)duration
                      rotateEnabled:(BOOL)needRotate;

/**
 * @brief  执行平滑移动动画. 该方法支仅持地图在2D正北状态下进行.
 * @param annotationView  平滑移动的对象
 * @param rotationView   旋转的对象
 * @param locations     平滑移动需要经过的经纬度坐标点串
 * @param duration        平滑移动时间
 * @param needRotate      平滑移动过程中annotationView是否需要沿移动方向执行旋转动画
 * @param distanceFilter  平滑移动回调频率接口，单位: 米
 * @param callBack		平滑移动回调
 */
+ (void)translateWithAnnotationView:(QAnnotationView *)annotationView
						rotationView:(UIView *)rotationView
						  locations:(NSArray<id <QMULocation> > *)locations
						   duration:(CFTimeInterval)duration
					  rotateEnabled:(BOOL)needRotate
					  distanceFilter:(CLLocationDistance)distanceFilter
					  translationCallback:(QMUAnnotationAnimationCallBack)callBack;

/**
 * @brief  更改当前进行的平移动画的位置并执行平移动画. 该方法支仅持地图在2D正北状态下进行且须先执行平移动画.
 * @param annotationView  平滑移动的对象
 * @param index 起点下标 取值[0，length - 1), length为点串长度
 * @param ratio 当前segment的比例值 取值[0, 1]
 */
+(void)setTranslation:(QAnnotationView *)annotationView withPoint:(int)index andRatio:(float)ratio;

/**
 * @brief  更改当前进行的平移动画的动画时间并执行平移动画. 该方法支仅持地图在2D正北状态下进行且须先执行平移动画.
 * @param annotationView  平滑移动的对象
 * @param time 剩余时间
 */
+(void)setAnimation:(QAnnotationView *)annotationView withLeftTime:(CFTimeInterval)time;

/**
 * @brief  更改当前进行的平移动画的动画时间和位置并执行平移动画. 该方法支仅持地图在2D正北状态下进行且须先执行平移动画.
 * @param annotationView  平滑移动的对象
 * @param index 起点下标 取值[0，length-1), length为点串长度
 * @param ratio 当前segment的比例值 取值[0, 1]
 * @param time 剩余时间
 */
+(void)setTranslation:(QAnnotationView *)annotationView withPoint:(int)index andRatio:(float)ratio andLeftTime:(CGFloat)time;

@end



