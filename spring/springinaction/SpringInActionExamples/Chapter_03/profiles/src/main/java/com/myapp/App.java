package com.myapp;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.core.env.AbstractEnvironment;

public class App {
  public static void main(String[] args) {
    System.setProperty(AbstractEnvironment.ACTIVE_PROFILES_PROPERTY_NAME, "dev");
    ApplicationContext context = new AnnotationConfigApplicationContext(DataSourceConfig.class);
    //context.getEnvironment().setActiveProfiles("dev");
    String x = (String) context.getBean("x");
    System.out.println(x);
  }
}


