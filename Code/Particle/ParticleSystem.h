//
// Created by Doni on 02.07.2023.
//

#ifndef GAMEENGINE_BROUGHT_PARTICLESYSTEM_H
#define GAMEENGINE_BROUGHT_PARTICLESYSTEM_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

using namespace sf;
using namespace std;


class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

    ParticleSystem(unsigned int count) :
            m_particles(count),
            m_vertices(sf::Points, count),
            m_lifetime(sf::seconds(3.f)),
            m_emitter(0.f, 0.f){}

    void setEmitter(sf::Vector2f position)
    {
        this->m_emitter = position;
    }
    void setEmitter(float x, float y)
    {
        this->m_emitter.x = x;
        this->m_emitter.y = y;
    }

    void update(sf::Time elapsed)
    {
        for (std::size_t i = 0; i < m_particles.size(); ++i)
        {
            // обновляем время жизни частицы
            Particle& p = m_particles[i];
            p.lifetime -= elapsed;

            // if the particle is dead, respawn it
            if (p.lifetime <= sf::Time::Zero)
                resetParticle(i);

            // update the position of the corresponding vertex
            m_vertices[i].position += p.velocity * elapsed.asSeconds();

            // обновляем альфу (прозрачность) частицы в соответствии с ее временем жизни
            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
            m_vertices[i].color.a = 255;
            m_vertices[i].color.b = 155;
            m_vertices[i].color.g = 155;}
    }
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // применяем трансформацию
        states.transform *= getTransform();

        // наши частицы не используют текстуру
        states.texture = NULL;

        // рисуем массив вершин
        target.draw(m_vertices, states);
    }

    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index)
    {
        // придаем случайную скорость и время жизни частице
        float angle = (std::rand() % 360) * 3.14f / 260.f;
        float speed = (std::rand() % 40) + 40.f; // Высота частиц
        m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed); // если выключить, то можно
        m_particles[index].lifetime = sf::milliseconds((std::rand() % 1000) + 500);

        // сбрасываем позицию соответствующей вершины
        m_vertices[index].position = m_emitter;
    }

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
};


#endif //GAMEENGINE_BROUGHT_PARTICLESYSTEM_H
