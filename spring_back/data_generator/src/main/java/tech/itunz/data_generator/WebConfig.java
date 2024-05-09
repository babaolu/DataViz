package tech.itunz.data_generator;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.*;

@Configuration
@EnableWebMvc
@ComponentScan(basePackages = {"tech.itunz.data_generator"})
public class WebConfig implements WebMvcConfigurer
{
    @Override
    public void addResourceHandlers(final ResourceHandlerRegistry registry)
    {
        WebMvcConfigurer.super.addResourceHandlers(registry);
        registry.addResourceHandler("/images/**", "styles/**", "scripts/**")
        .addResourceLocations("/images/", "/styles/", "/scripts/");
    }

    @Override
    public void configureDefaultServletHandling(final DefaultServletHandlerConfigurer configurer)
    {
        configurer.enable();
    }

    /*@Override
    public void addViewControllers(ViewControllerRegistry registry)
    {
        registry.addRedirectViewController("/", "/home");
    }*/

    /*
    @Override
    public void addCorsMappings(CorsRegistry registry)
    {
        registry.addMapping("/**")
        .allowedOrigins("http://localhost:3000")
        .allowedMethods("*")
        .allowedHeaders("*")
        .allowCredentials(true).maxAge(3600);
    }*/
}
