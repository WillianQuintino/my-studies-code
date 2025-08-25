import React from 'react';
import { View, Text, Image, StyleSheet } from 'react-native';
import SkillItem from '../components/SkillItem';

export default function SkillScreen() {
    return (
        <View style={styles.container}>
            <Image source={require('../../assets/profile.jpg')} style={styles.photo} />
            <Text style={styles.name}>Willian Custodio Quintino</Text>
            <Text style={styles.title}>Habilidades</Text>
            <SkillItem skill="React Native" level="Avançado" />
            <SkillItem skill="TypeScript" level="Intermediário" />
            <SkillItem skill="JavaScript" level="Avançado" />
            <SkillItem skill="Node.js" level="Intermediário" />
        </View>
    );
}

const styles = StyleSheet.create({
    container: { flex: 1, alignItems: 'center', backgroundColor: '#fff', paddingTop: 40 },
    photo: { width: 100, height: 100, borderRadius: 50, marginBottom: 12 },
    name: { fontSize: 22, fontWeight: 'bold', marginBottom: 8 },
    title: { fontSize: 18, fontWeight: '600', marginVertical: 16 },
});