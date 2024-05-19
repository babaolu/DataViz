package tech.itunz.data_generator;

import java.util.List;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpMethod;
import org.springframework.web.cors.CorsConfiguration;
import org.springframework.web.cors.CorsConfigurationSource;
import org.springframework.web.cors.UrlBasedCorsConfigurationSource;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.web.SecurityFilterChain;

/**
 * Security class for future additions
 */
@EnableWebSecurity
@Configuration
public class WebSecurityConfig {
    @Bean
    public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception
    {
        return http
        .authorizeHttpRequests(authorize -> authorize
        .requestMatchers(HttpMethod.GET, "gen_pdata").permitAll()
        .requestMatchers(HttpMethod.POST, "gen_pdata").permitAll()
        .requestMatchers(HttpMethod.HEAD, "gen_pdata").permitAll()
        .requestMatchers(HttpMethod.OPTIONS, "gen_pdata").permitAll()
        .anyRequest().authenticated())
        .cors(cors -> cors.configurationSource(corsConfigurationSource()))
        .build();
    }

    @Bean
    public CorsConfigurationSource corsConfigurationSource()
    {
        UrlBasedCorsConfigurationSource source = new UrlBasedCorsConfigurationSource();
        CorsConfiguration config = new CorsConfiguration();
        config.setAllowedOriginPatterns(List.of("http://*:3000"));
        config.setAllowedMethods(List.of("*"));
        config.setAllowedHeaders(List.of("*"));
        config.setAllowCredentials(true);
        config.setMaxAge(3600L);
        source.registerCorsConfiguration("/**", config);
        return source;
    }
}
