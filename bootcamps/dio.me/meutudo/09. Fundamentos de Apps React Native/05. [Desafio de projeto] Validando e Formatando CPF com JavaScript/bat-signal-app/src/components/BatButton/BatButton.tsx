import React from 'react';
import { Text, Pressable } from 'react-native';

import { styles } from './BatButtonStyles';

interface BatButtonProps {
    text?: string;
    onPress?: () => void;
}


export function BatButton({ onPress, text }: BatButtonProps) {

    return (
        <>
            <Pressable
                onPress={onPress}
                style={styles.button}
            >
                <Text style={styles.text}>{ text ? text : "Texto generico"}</Text>
            </Pressable>
        </>
    );
}