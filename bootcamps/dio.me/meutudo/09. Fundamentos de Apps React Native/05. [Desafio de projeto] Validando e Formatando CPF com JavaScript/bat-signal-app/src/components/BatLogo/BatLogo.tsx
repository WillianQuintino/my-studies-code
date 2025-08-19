import React from 'react';
import { Image} from 'react-native';

import { styles } from './BatLogoStyles';
import batLogo from '../../../assets/bat-logo.png';

interface BatLogoProps {
    style?: object;
}

export function BatLogo({ style }: BatLogoProps) {
    return (
        <Image
            source={batLogo}
            style={[styles.image, style]}
        />
    );
}