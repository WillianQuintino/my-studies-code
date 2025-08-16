import { StyleSheet } from 'react-native';

export const styles = StyleSheet.create({
    logoOffContainer: {
        flex: 1,
        padding: 16,
        backgroundColor: '#fff',
        alignItems: 'center',
        justifyContent: 'center',
    },
    logoOffImg: {
        width: 180,
        height: 180,
        resizeMode: 'contain',
    },
    logoOnContainer: {
        padding: 16,
        paddingTop: 32,
        flex: 1,
        gap: 16,
        backgroundColor: '#fff',
        alignItems: 'flex-start',
        justifyContent: 'flex-start',
    },
    logoOnImg: {
        width: 80,
        height: 80,
        resizeMode: 'contain',
    },

});