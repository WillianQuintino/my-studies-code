import React from 'react';
import { Text, TextInput } from 'react-native';

import { styles } from './FormStyles';

export function Form() {
    return (
        <>
            <TextInput
                style={styles.inputer}
                placeholder="Text"
            />
            <Text style={styles.label}>Label</Text>
            <TextInput
                style={styles.inputer}
                placeholder="Text"
            />
            <Text style={styles.hint}>Thie is yout hint</Text>
            <TextInput
                style={styles.textInput}
                multiline
                numberOfLines={3}
                placeholder="Text"
            />
            <Text style={styles.label}>Label</Text>
            <TextInput
                style={styles.textInput}
                multiline
                numberOfLines={3}
                placeholder="Text"
            />
            <Text style={styles.hint}>This is your hint</Text>

        </>
    );
}