import React from 'react';
import { View, Text, Image, StyleSheet, TouchableOpacity, Linking } from 'react-native';
import SocialLink from '../components/SocialLink';

import type { NativeStackNavigationProp } from '@react-navigation/native-stack';

type RootStackParamList = {
    Main: undefined;
    Skills: undefined;
};

type MainScreenNavigationProp = NativeStackNavigationProp<RootStackParamList, 'Main'>;

type Props = {
    navigation: MainScreenNavigationProp;
};

export default function MainScreen({ navigation }: Props) {
    return (
        <View style={styles.container}>
            <Image source={require('../../assets/profile.jpg')} style={styles.photo} />
            <Text style={styles.name}>Willian Custodio Quintino</Text>
            <SocialLink label="LinkedIn" url="https://linkedin.com/in/willian-custodio-quintino" />
            <SocialLink label="GitHub" url="https://github.com/WillianQuintino" />
            <SocialLink label="Email" url="mailto:williancustodioquintino@gmail.com" />
            <TouchableOpacity style={styles.button} onPress={() => navigation.navigate('Skills')}>
                <Text style={styles.buttonText}>Ver Habilidades</Text>
            </TouchableOpacity>
        </View>
    );
}

const styles = StyleSheet.create({
    container: { flex: 1, alignItems: 'center', justifyContent: 'center', backgroundColor: '#fff' },
    photo: { width: 120, height: 120, borderRadius: 60, marginBottom: 16 },
    name: { fontSize: 24, fontWeight: 'bold', marginBottom: 24 },
    button: { marginTop: 32, backgroundColor: '#222', padding: 12, borderRadius: 8 },
    buttonText: { color: '#fff', fontSize: 16 },
});