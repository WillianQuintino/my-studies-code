import React from 'react';
import { TouchableOpacity, Text, StyleSheet, Linking } from 'react-native';

type SocialLinkProps = {
  label: string;
  url: string;
};

export default function SocialLink({ label, url }: SocialLinkProps) {
  return (
    <TouchableOpacity style={styles.link} onPress={() => Linking.openURL(url)}>
      <Text style={styles.text}>{label}</Text>
    </TouchableOpacity>
  );
}

const styles = StyleSheet.create({
  link: { marginVertical: 4 },
  text: { color: '#0072b1', fontSize: 16, textDecorationLine: 'underline' },
});