-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find crime scene description
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2024 AND
street = "Humphrey Street";


-- Find transcript that mentions bakery
SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2024 AND transcript LIKE '%baker%';


-- People who left the bakery on that day b/w that time
SELECT people.name FROM people JOIN bakery_security_logs AS bsl ON bsl.license_plate = people.license_plate WHERE bsl.year = 2024 AND bsl.month = 7 AND bsl.day = 28 AND bsl.hour = 10 AND bsl.minute BETWEEN 15 AND 25;
-- Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey


-- Find people who withdrew money from atm that day on Leggett Street
SELECT people.name FROM people JOIN bank_accounts AS ba ON ba.person_id = people.id JOIN atm_transactions AS at ON at.account_number = ba.account_number WHERE at.year = 2024 AND at.month = 7 AND at.day = 28 AND at.atm_location = 'Leggett Street' AND at.transaction_type = 'withdraw';
-- Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista


-- Find people who made a call on that day for less than a min
SELECT people.name FROM people JOIN phone_calls AS pc ON pc.caller = people.phone_number WHERE pc.year = 2024 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60;
-- Sofia, Kelsey, Bruce, Taylor, Diana, Carina, Kenny, Benista


-- Find people who received on that day for less than a min
SELECT people.name FROM people JOIN phone_calls AS pc ON pc.receiver = people.phone_number WHERE pc.year = 2024 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60;
-- Jack, Larry, Robin, Melissa, James, Philip, Jacqueline , Doris, Anna

-- So common names FROM bakery and atm and phone call are: Bruce, Diana


-- Find who bruce phone number, so we will figure out receiver
SELECT phone_number FROM people WHERE name = 'Bruce';
-- (367) 555-5533


-- Find receiver number
SELECT caller, receiver, duration FROM phone_calls WHERE year = 2024 AND month = 7 AND day = 28 AND caller = (SELECT phone_number FROM people WHERE name = 'Bruce');
-- (375) 555-8161

-- Find receiver name
SELECT name FROM people WHERE phone_number = '(375) 555-8161';
-- ROBIN


-- Find flight id of Bruce, Diana
SELECT people.name, pas.flight_id FROM people JOIN passengers AS pas ON people.passport_number = pas.passport_number WHERE people.name IN ('Bruce', 'Diana');
-- Bruce (flight_id = 36)


-- Find earliest flight on 29
SELECT id,origin_airport_id, destination_airport_id FROM flights WHERE year = 2024 AND month = 7 AND day = 29 ORDER BY hour ASC LIMIT 1;
-- So Bruce (flight_id = 36) took the flight AND destination_airport_id = 4


-- Find Destination city
SELECT full_name, city FROM airports WHERE id = 4;
-- New York City
