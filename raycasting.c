/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 07:04:47 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/24 12:22:49 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double degress_to_radian(double degress)
{
    return degress * (M_PI/180.0);
}
// const FOV_ANGLE = 60* (math.PI / 180);
// const NUM_RAYS = 320;
// //..
// rayAngle += FOV_ANGLE / NUM_RAYS;

void calculateFOVAndRays(double *fovAngle, int *numRays) 
{
    *fovAngle = 60.0 * (M_PI / 180.0);  // Calculate FOV angle in radians
    *numRays = 320;                     // Set the number of rays
}

int main() {
    double fovAngle;  // Declare FOV angle
    int numRays;      // Dec lare number of rays
    double rayAngle = 0.0;  // Initialize the ray angle

    // Call the function to calculate FOV angle and number of rays
    calculateFOVAndRays(&fovAngle, &numRays);

    // Use fovAngle and numRays as needed
    rayAngle += fovAngle / numRays;

    // Rest of your code

    return 0;
}

// Define a structure for representing a point with x and y coordinates
struct Point {
    double x;
    double y;
};

// Function to calculate the distance between two points A and B
double calculateDistance(struct Point A, struct Point B) {
    double distance = sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
    return distance;
}

int main() {
    // Define two points A and B
    struct Point A = {1.0, 2.0};
    struct Point B = {4.0, 6.0};

    // Call the calculateDistance function to compute the distance
    double distanceab = calculateDistance(A, B);

    // Print the result
    printf("The distance between A and B is: %lf\n", distanceab);

    return 0;
}



