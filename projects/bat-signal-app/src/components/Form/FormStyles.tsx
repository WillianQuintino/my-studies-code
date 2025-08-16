import { StyleSheet } from 'react-native';

export const styles = StyleSheet.create({
    inputer: {
        width: '100%',
        borderWidth: 2,
        borderColor: 'black',
        borderRadius: 4,
        paddingVertical: 8,
        paddingHorizontal: 12,
    },
    textInput: {
        width: '100%',
        height: 'auto',
        borderWidth: 2,
        borderColor: 'black',
        borderRadius: 4,
        paddingVertical: 8,
        paddingHorizontal: 12,
        textAlignVertical: 'top',

    },
    label: {
        fontSize: 16,
        fontWeight: 'bold',
        marginBottom: 4,
        color: 'black',
    },
    hint: {
        fontSize: 14,
        color: 'gray',
        marginTop: 4,
        marginBottom: 8,
    },
});