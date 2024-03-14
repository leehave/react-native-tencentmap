import { NativeModules } from 'react-native';

type TencentmapType = {
  multiply(a: number, b: number): Promise<number>;
};

const { Tencentmap } = NativeModules;

export default Tencentmap as TencentmapType;
