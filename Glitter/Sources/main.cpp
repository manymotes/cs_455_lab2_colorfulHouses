// Local Headers
#include "glitter.hpp"
#include "ShaderHelpers.h"

// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standard Headers
#include <cstdio>
#include <cstdlib>

int main(int argc, char * argv[]) {
    
    

    
    // Load GLFW and Create a Window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    auto mWindow = glfwCreateWindow(mWidth, mHeight, "OpenGL", nullptr, nullptr);
    
    

    // Check for Valid Context
    if (mWindow == nullptr) {
        fprintf(stderr, "Failed to Create OpenGL Context");
        return EXIT_FAILURE;
    }

    // Create Context and Load OpenGL Functions
    glfwMakeContextCurrent(mWindow);
    gladLoadGL();
    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));

	// **************************************
	// Setup Vertex arrays here
	// **************************************
    
    //load shader
    GLuint myShader = LoadProgram("/Users/kendall/Glitter/Glitter/Shaders/basic.vert", "/Users/kendall/Glitter/Glitter/Shaders/basic.frag");
    

    
    /*
     GLfloat pentagon_vertex_buffer[] = {
     /Pentagon
     0.25f, 0.25f, 1.0f,
     0.75f, 0.25f, 1.0f,
     0.25f, 0.5f, 1.0f,
     
     0.25f, 0.5f, 1.0f,
     0.75f, 0.25f, 1.0f,
     0.75f, 0.5f, 1.0f,
     
     0.25f, 0.5f, 1.0f,
     0.75f, 0.5f, 1.0f,
     0.5f, .75f, 1.0f,
     }
     */
    glTranslatef(0.2f, 0.2f, 0.0f);
     GLfloat g_vertex_buffer_data[] = {
         
//        //triangle
//         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
//         -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
//         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
         

        //Pentagon
        -0.25f, 0.25f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.75f, 0.25f, 1.0f,  0.0f, 0.0f, 1.0f,
        -0.25f, 0.5f, 1.0f, 1.0f, 0.0f, 0.0f,
        
       - 0.25f, 0.5f, 1.0f, 1.0f, 0.0f, 0.0f,
       - 0.75f, 0.25f, 1.0f,  0.0f, 0.0f, 1.0f,
         -0.75f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
        
       - 0.25f, 0.5f, 1.0f, 1.0f, 0.0f, 0.0f,
       - 0.75f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
       - 0.5f, .75f, 1.0f, 0.0f, 1.0f, 0.0f
         
    };
   
    
    // This will identify our vertex buffer
    GLuint vertexbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    //add vertex array
    unsigned int vaoID[1]; // Our Vertex Array Object
    glGenVertexArrays(1, &vaoID[0]); // Create our Vertex Array Object
    //bind vertex array
    glBindVertexArray(vaoID[0]); // Bind our Vertex Array Object so we can use it
    
    
    //loading hte color is going to be very simular to these calls
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    
   // glm::mat4 myMatrix = glm::translate(glm::mat4(), glm::vec3(10.0f, 0.0f, 0.0f));
    
    
    glm::mat4 modelviewMatrix;
     modelviewMatrix = glm::translate(
                                               modelviewMatrix,
                                               glm::vec3(0.20f, -0.20f, 0.0f));
    
    //glm::mat4 = g_vertex_buffer_data * modelviewMatrix
    
    
    // Draw the triangle !
   
	
    // Rendering Loop
    while (glfwWindowShouldClose(mWindow) == false) {
        if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(mWindow, true);

        // Background Fill Color
        
        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		// **********************************
		// Add rendering code here
        
        
        
      
        //get my vertexarray and bind it
        
        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        int vertexColorLocation = glGetUniformLocation(myShader, "color");


        glUseProgram(myShader);
        

        
    
        GLint unifomrNumber = glGetUniformLocation(myShader, "transformation");
        
        //GLint uniformSclae = glad_glGetUniformLocation(myShader, "scale");
        
        
        
        
        glm::mat4 modelviewInit;
        modelviewInit = glm::translate(
                                         modelviewMatrix,
                                         glm::vec3(0.1f, -0.1f, 0.0f));
        modelviewInit= glm::scale(modelviewInit, glm::vec3(0.5f, 0.5f, 0.0f));

        
        glUniformMatrix4fv(	unifomrNumber,
                           1,
                           GL_FALSE,
                           glm::value_ptr(modelviewInit));
        
        //call 3 times
        glDrawArrays(GL_TRIANGLES, 0, 27); // Starting from vertex 0; 3 vertices total -> 1 triangle
        
        
        glUniformMatrix4fv(	unifomrNumber,
                            1,
                           GL_FALSE,
                           glm::value_ptr(modelviewMatrix));
        
        glDrawArrays(GL_TRIANGLES, 0, 27);
        
        glm::mat4 modelviewfinal;
        modelviewfinal = glm::translate(
                                       modelviewMatrix,
                                       glm::vec3(0.9f, -0.9f, 0.0f));
        modelviewfinal= glm::scale(modelviewfinal, glm::vec3(1.5f, 1.5f, 0.0f));
        
        glUniformMatrix4fv(	unifomrNumber,
                           1,
                           GL_FALSE,
                           glm::value_ptr(modelviewfinal));
        
        //call 3 times
        glDrawArrays(GL_TRIANGLES, 0, 27); // Starting from vertex 0; 3 vertices total -> 1 triangle

        
        
        // **********************************

        // Flip Buffers and Draw
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }   glfwTerminate();

    return EXIT_SUCCESS;
}
