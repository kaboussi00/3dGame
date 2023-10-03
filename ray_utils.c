/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:11:27 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/01 11:11:29 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// haswall(x, y){
//     if (x < 0 || x > WINDOW_width || y < 0 || y > WINDOW_HETGHT){
//         return true; 
//     }
//     var mapgridindexX = math.floor(x/ TILT_SIZE);
//     var mapgridindeY = math.floor(Y/ TILT_SIZE);
//     return grid [mapgridindexX][mapgridindexY] != 0;
// }


void    Castarays(t_cub *cub)
{
    double column;
    double rayAngl;
    double ray;
    double fov;

    column = 0;
    rayAngl = cub->player.rotationangle - (fov/3);
    while (column < 0)
    {
        ray = 
    }
}

void castRays(t_cub *cub)
{
    int column = 0;
    int ray = 0;

    // START FIRST RAY SUBTRACTING HALF OF THE FOV
    double rayAngle = cub->player.rotationangle - (FOV_ANGLE / 2);

    // LOOP ALL COLUMNS CASTING RAYS
    while (column < 0)
    for (int i = 0; i < NUM_RAYS; i++) {
        // Call a function to cast a single ray
        Ray ray;
        ray.x = player.x; // Replace with actual ray casting logic
        ray.y = player.y; // Replace with actual ray casting logic

        // Next ray in the last ray incremented by FOV_ANGLE
        rayAngle += (FOV_ANGLE / NUM_RAYS);

        column++;
    }
}

function castarrays(){
    var colunb = 0;

    //START FIRST RAY SUBRACTIMG HALF OF THE FOV
    var rayangle = player.rotaion angle - (fov_angle / 2);

    //LOOP ALL COLUMNS CASTING RAYS
    for(var i - 0, i < NUM_RAYS; i++){
        // call function to cast a single ray
        var ray = new (ray_angle);
        ray.cast(column);

        //next ray in last ray incremented by fov_angle
        ray_angle += ( fov_angle / num_rays);
        
        colimn++;
    }
}