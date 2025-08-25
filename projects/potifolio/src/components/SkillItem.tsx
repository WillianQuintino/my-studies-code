import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

type SkillItemProps = {
  skill: string;
  level: string | number;
};

export default function SkillItem({ skill, level }: SkillItemProps) {
  return (
    <View style={styles.item}>
      <Text style={styles.skill}>{skill}</Text>
      <Text style={styles.level}>{level}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  item: { flexDirection: 'row', justifyContent: 'space-between', width: 220, marginVertical: 6 },
  skill: { fontSize: 16, fontWeight: '500' },
  level: { fontSize: 16, color: '#555' },
});