import React from 'react';
import { StyleProp, Text, View, ViewStyle } from 'react-native';

import { styles } from './HomeStyles';
import { StatusBar } from 'expo-status-bar';
import { BatLogo } from '../../components/BatLogo/BatLogo';
import { BatButton } from '../../components/BatButton/BatButton';
import { Form } from '../../components/Form/Form';

export function Home() {
    const defaultBatSignal = {
        containerStyle: styles.logoOffContainer as StyleProp<ViewStyle>,
        imageStyle: styles.logoOffImg,
        isActive: false,
        button: 'activate bat signal',
    }

    const [batSignalActivated, setBatSignalActivated] = React.useState(defaultBatSignal);

    const handleBatSignalToggle = () => {
        if (batSignalActivated.isActive) {
            setBatSignalActivated(defaultBatSignal);
            return;
        } else {
            setBatSignalActivated({
                containerStyle: styles.logoOnContainer,
                imageStyle: styles.logoOnImg,
                isActive: true,
                button: 'Enviar',
            });
        }
    }

    return (
        <View style={batSignalActivated.containerStyle}>
            <BatLogo style={batSignalActivated.imageStyle} />

            {batSignalActivated.isActive && (
                <View style={{ 
                    width: '100%',
                    gap: 16,
                }}>
                    <Form />
                </View>
            )}

            <View style={{ 
                width: '100%',
                alignItems: 'center',
                justifyContent: 'center',
            }}>
                <BatButton
                    text={batSignalActivated.button}
                    onPress={handleBatSignalToggle}
                />
            </View>
            <StatusBar style="auto" />
        </View>
    );
}