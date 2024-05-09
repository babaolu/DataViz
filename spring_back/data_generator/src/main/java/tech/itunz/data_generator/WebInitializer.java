package tech.itunz.data_generator;

import org.springframework.web.filter.CharacterEncodingFilter;
import org.springframework.web.filter.HiddenHttpMethodFilter;
import org.springframework.web.servlet.support.
AbstractAnnotationConfigDispatcherServletInitializer;

import jakarta.servlet.Filter;
import java.nio.charset.StandardCharsets;

public class WebInitializer
extends AbstractAnnotationConfigDispatcherServletInitializer
{
    protected Class<?>[] getRootConfigClasses()
    {
        return new Class[]{};
    }

    @Override
    protected Class<?>[] getServletConfigClasses()
    {
        return new Class[]{WebConfig.class};
    }

    @Override
    protected String[] getServletMappings()
    {
        return new String[]{"/"};
    }
    @Override
    protected Filter[] getServletFilters()
    {
        final CharacterEncodingFilter cef = new CharacterEncodingFilter();
        cef.setEncoding(StandardCharsets.UTF_8.name());
        cef.setForceEncoding(true);
        return new Filter[]{new HiddenHttpMethodFilter(), cef};
    }
}
